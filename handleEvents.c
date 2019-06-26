#include "handleEvents.h"

int processEvents(PC *player) {
    SDL_Event event;
    int done = 0;

    while(SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            done = 1;
        }
    }

    const Uint8 *keystate = SDL_GetKeyboardState(NULL);
    
    if (keystate[SDL_SCANCODE_A]) {
        player->x -= 3;
        player->walking = 1;
        player->facingLeft = 1;
    }
    else if(keystate[SDL_SCANCODE_D]) {
        player->x += 3;
        player->walking = 1;
        player->facingLeft = 0;
    }
    else {
        player->walking = 0;
    }

    if(keystate[SDL_SCANCODE_W] && player->dy==0 && player->y==200-eachFramey) {
        player->dy = -8;
    }
    
    
    // if(keystate[SDL_SCANCODE_DOWN])
    // {
    //     //player->y += 10;  change to mario's crouch animation
    // }

    return done;
}
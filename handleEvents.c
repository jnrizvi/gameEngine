#include "headers/handleEvents.h"

int processEvents(Agent *agent, int *curX, int *curY, int *delay) {
    SDL_Event event;
    int done = 0;
    float normalSpeed = 3;
    int refGrid[][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 1, 1, 0}
    };
    
    while(SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            done = 1;
        }
    }

    const Uint8 *keystate = SDL_GetKeyboardState(NULL);
    

    if (keystate[SDL_SCANCODE_A]) {
        *curY = ((agent->coll.rightEdge) / 32);
        if (*curY > 3) {
            *curY = 3;
        }
        if ((*curY > 0) ) {
            move(agent, -normalSpeed, 0);
        }
    }

    else if(keystate[SDL_SCANCODE_D]) {
        *curY = ((agent->coll.leftEdge) / 32);
        if (*curY > 3) {
            *curY = 3;
        }
        if ((*curY < 4) && (agent->coll.rightEdge+normalSpeed<=128)) {
            move(agent, normalSpeed, 0);
        }
    }
    
    if (keystate[SDL_SCANCODE_W] && (agent->jumpAgain==true)) {
        agent->dy = -10;
        agent->jumpAgain = false;
        // *curX = ((agent->coll.top) / 32);
        
        // if ((*curX >= 0) && (agent->coll.top>0) ) {
        //     move(agent, -normalSpeed, 1);
        // }
    }

    // else if (keystate[SDL_SCANCODE_S]) {
    //     *curX = ((agent->coll.bottom) / 32);
    //     if (*curX > 6) {
    //         *curX = 6;
    //     }
    //     if ((*curX < 7) && (agent->coll.bottom<=192)) {
    //         move(agent, normalSpeed, 1);
    //     }
    // }

    return done;
}

void move(Agent *agent, int distance, int dir) {
    if (dir == 0) {
        if (distance>0) {
            agent->facingLeft = 0;
        }
        else {
            agent->facingLeft = 1;
        }
        agent->x += distance;
        agent->coll.leftEdge += distance;
        agent->coll.rightEdge += distance;
    }
    else {
        agent->y += distance;
        agent->coll.top += distance;
        agent->coll.bottom += distance;
        
    }
}



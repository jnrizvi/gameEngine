#include "headers/handleEvents.h"
#include "headers/physics2d.h"

int eventHandler(Agent *agent, Coll allRects, int numRects) {
    SDL_Event event;
    int done = 0;
    float normalSpeed = 3;
    float moveDirection[4] = {0, 0, 0, 0};
    SDL_Rect testBrick;

    testBrick.x = 352;
    testBrick.y = 224;
    testBrick.w = 32;
    testBrick.h = 32;

    while(SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            done = 1;
        }
    }

    const Uint8 *keystate = SDL_GetKeyboardState(NULL);

    if (keystate[SDL_SCANCODE_A]) {
        moveDirection[0] = -normalSpeed;
        move(agent, moveDirection);
        // move(agent, -normalSpeed, 0);
        // move(agent, collideRect(agent, &testBrick), 0);
        agent->facingLeft = 1;
        moveDirection[0] = 0;
    }
    else if (keystate[SDL_SCANCODE_D]) {
        moveDirection[1] = normalSpeed;
        move(agent, moveDirection);
        // move(agent, normalSpeed, 0);
        // move(agent, -collideRect(agent, &testBrick), 0);
        agent->facingLeft = 0;
        moveDirection[1] = 0;
    }
    if (keystate[SDL_SCANCODE_W]) {
        moveDirection[2] = -normalSpeed;
        move(agent, moveDirection);
        // move(agent, -normalSpeed, 1);
        // move(agent, collideRect(agent, &testBrick), 1);
        moveDirection[2] = 0;
    }
    else if (keystate[SDL_SCANCODE_S]) {
        moveDirection[3] = normalSpeed;
        move(agent, moveDirection);
        // move(agent, normalSpeed, 1);
        // move(agent, -collideRect(agent, &testBrick), 1);
        moveDirection[3] = 0;
    }

    // move(agent, collideRect(agent, &testBrick));
    
    return done;
}

void move(Agent *agent, float moveDirection[4]) {
    if (moveDirection[0] != 0) {
        agent->x += moveDirection[0];
        agent->coll.leftEdge += moveDirection[0];
        agent->coll.rightEdge += moveDirection[0];
    }
    else if (moveDirection[1] != 0) {
        agent->x += moveDirection[1];
        agent->coll.leftEdge += moveDirection[1];
        agent->coll.rightEdge += moveDirection[1];
    }
    else if (moveDirection[2] != 0) {
        agent->y += moveDirection[2];
        agent->coll.top += moveDirection[2];
        agent->coll.bottom += moveDirection[2];
    }
    else if (moveDirection[3] != 0) {
        agent->y += moveDirection[3];
        agent->coll.top += moveDirection[3];
        agent->coll.bottom += moveDirection[3];   
    }

}

// void move(Agent *agent, int distance, int dir) {
//     if (dir == 0) {
//         if (distance>0) {
//             agent->facingLeft = 0;
//         }
//         else {
//             agent->facingLeft = 1;
//         }
//         agent->x += distance;
//         agent->coll.leftEdge += distance;
//         agent->coll.rightEdge += distance;
//     }
//     else {
//         agent->y += distance;
//         agent->coll.top += distance;
//         agent->coll.bottom += distance;
        
//     }
// }



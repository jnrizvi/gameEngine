#include "headers/physics2d.h"

void collideRect(Agent *agent, Platform *platform) {

}

void changePlatforms(Agent *agent, Platform platforms[2], int *current_platform, bool *noMorePlat) {
    bool incremented = false;
    for (int i =0; i <= *current_platform; i++) {
        if (*current_platform >= 2) {
            printf("You fell off!\n");
            *noMorePlat = true;
            *current_platform -= 1;
        }
        // printf("agent->y: %f, *current_platform: %d\n", agent->y, *current_platform);
        if (onLedge(agent, &platforms[*current_platform]) == 0) {
            // printf("remained on platform %d\n", *current_platform);
            incremented = false;
            break;
        }
        else if (onLedge(agent, &platforms[*current_platform]) == 1) {
            if (incremented == false && *current_platform <= 1) {
                // printf("*current_platform: %d\n", *current_platform);
                *current_platform += 1;
                incremented = true;
            }
        }
        
        // printf("agent->y: %f, *current_platform: %d\n", agent->y, *current_platform);
        if (*current_platform -1 >= 0) {
            // printf("agent->y: %f, *current_platform: %d\n", agent->y, *current_platform);
            if (agent->coll.bottom <= platforms[*current_platform-1].coll.top) {
                // jumped at the level of a platform above
                *current_platform -= 1;
            }
        }
    }
}

int onLedge(Agent *agent, Platform *platform) {
    int result;
    if ( agent->coll.bottom >= platform->coll.top) {
        // above/on the current platform
        if (agent->coll.rightEdge >= platform->coll.leftEdge && agent->coll.leftEdge <= platform->coll.rightEdge) {
            // remained on the current platform
            agent->y = platform->coll.top - agent->sprite_h;
            agent->jumpAgain = true;
            agent->coll.bottom = platform->coll.top; 
            agent->coll.top = agent->y;                                                                            
            agent->dy = 0;
            result = 0; 
        }
        else {
            // fell off the current platform
            result = 1;
        }    
    }
    return result;
}

void gravity(Agent *agent) {
    agent->y += agent->dy;
    agent->coll.bottom += agent->dy;
    agent->coll.top += agent->dy;
    agent->dy += 0.5;
}
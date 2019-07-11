#include "headers/physics2d.h"

void collideRect(Agent *agent, Platform *platform) {

}

void changePlatforms(Agent *agent, Platform platforms[], int *current_platform, bool *noMorePlat, int lenPlatforms) {
    bool incremented = false;
    // printf("lenPlatforms: %d\n", lenPlatforms);

    for (int i =0; i <= *current_platform; i++) {
        if (*current_platform >= lenPlatforms+1) {
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
            if (incremented == false && *current_platform <= lenPlatforms) {
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
            
            agent->jumpAgain = true;
            agent->falling = false;
            
            result = 0; 
        }
        else {
            // fell off the current platform
            agent->falling = true;
            result = 1;
        }    
    }
    return result;
}

void gravity(Agent *agent) {
    if (agent->falling == true) {
        agent->y += agent->dy;
        agent->coll.bottom += agent->dy;
        agent->coll.top += agent->dy;
        agent->dy += 0.5;
    }
    else {
        agent->dy = 0;
    }
}
#ifndef PHYSICS_2D
#define PHYSICS_2D

#include "resources.h"

void bump(Agent *agent, Platform *platform);
void collideRect(Agent *agent, Platform *platform);
int changePlatforms(Agent *agent, Platform platforms[], int current_platform, bool *noMorePlat, int lenPlatforms);
int onLedge(Agent *agent, Platform *platform);
void gravity(Agent *agent, float *refY);

#endif /* PHYSICS_2D */
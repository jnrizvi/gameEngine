#ifndef HANDLE_EVENTS
#define HANDLE_EVENTS

#include <stdio.h>
#include "SDL2/SDL.h"
#include <stdbool.h>
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_image.h"

#define FPS 60

typedef struct {
    float x, y, dy;
    short life;
    char *name;
    int currentSprite, walking, facingLeft, shooting, visible;
    int alive;
    SDL_Texture *sheetTexture;
} PC;

int processEvents(PC *player);

#endif /* HANDLE_EVENTS */
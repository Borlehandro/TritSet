#pragma once 
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h> 

#define CXSCREEN 0x00000000
#define CYSCREEN 0x00000001

extern const int FIELD_WIDTH;
extern const int FIELD_HEIGHT;

extern const int DEFAULT_WINDOW_WIDTH;
extern const int DEFAULT_WINDOW_HEIGHT;
extern const int WINDOW_FLAGS;

int initialize();
void finalize();
int convert(SDL_Renderer *renderer, double value);
SDL_Point convert(SDL_Renderer *renderer, const SDL_Point &point);
int getDesktopMetrics(int flag);
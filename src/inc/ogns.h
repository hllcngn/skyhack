#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "menu.h"
#include "tools.h"

//palette
#define BLACK		(SDL_Color){0,0,0,0xFF}
#define DARKGRAY	(SDL_Color){89,86,82,0xFF}
#define RED		(SDL_Color){172,50,50,0xFF}
#define LIGHTBLUE	(SDL_Color){95,205,228,0xFF}
#define DARKBLUE	(SDL_Color){63,63,116,0xFF}

void new_game(SDL_Renderer* renderer, SDL_Window* window);
void load_game(SDL_Renderer* renderer, SDL_Window* window);
void start_game(SDL_Renderer* renderer, SDL_Window* window);

#pragma once

#define BLACK		(SDL_Color){0,0,0,0xFF}
#define RED		(SDL_Color){172,50,50,0xFF}
#define LIGHTBLUE	(SDL_Color){95,205,228,0xFF}
#define DARKBLUE	(SDL_Color){63,63,116,0xFF}

void clear_window(SDL_Renderer* renderer, SDL_Color color);

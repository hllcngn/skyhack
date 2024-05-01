#include <SDL2/SDL.h>

SDL_Init(SDL_INIT_VIDEO);
SDL_Window* window =SDL_CreateWindow("testtexdrawline",
		SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,600,400,
		SDL_WINDOW_SHOWN);
SDL_Renderer* renderer =SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED);

s =SDL_CreateRGBSurface(0, 300,200, 32,0,0,0,0);

SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();
return 0;}

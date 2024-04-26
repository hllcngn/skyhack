#include "SDL2/SDL.h"

#ifdef main
#undef main
#endif
int main(int ac, char** av){
SDL_Init(SDL_INIT_VIDEO);
SDL_Window   *window =SDL_CreateWindow("Of Glass And Steel",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		600, 400,
		SDL_WINDOW_SHOWN |SDL_WINDOW_BORDERLESS);
SDL_Renderer *renderer =SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED);

SDL_RenderPresent(renderer);
for(double i=0;i<1000000000;i++);

SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();
return 0;}

#include "ogns.h"

void start_game(SDL_Renderer* renderer, SDL_Window* window){
clear_window(renderer, BLACK);
SDL_RenderPresent(renderer);
for(int i=0; i<1000000000; i++);
return;}

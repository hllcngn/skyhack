#include "ogns.h"
#ifdef main
#undef main
#endif
int main(int ac, char** av){
//SDL init
SDL_Init(SDL_INIT_VIDEO);
TTF_Init();
SDL_Window   *window =SDL_CreateWindow("Of Glass And Steel",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		600, 400,
		SDL_WINDOW_SHOWN |SDL_WINDOW_RESIZABLE);
SDL_Renderer *renderer =SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED);

//run title menu
int title_return =menu_title(renderer, window);
switch(title_return){
case 's': //menu_settings()
		break;
case 'l': //menu_load_game()
		break;
case 'n': //new_game()
		break;
default:	break;}

//SDL end
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();
return 0;}


void new_game(SDL_Renderer* renderer, SDL_Window* window){
clear_window(renderer, BLACK);
return;}

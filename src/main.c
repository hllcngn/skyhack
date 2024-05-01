#include "ogns.h"
#ifdef main
#undef main
#endif
int main(int ac, char** av){
//SDL init
SDL_Init(SDL_INIT_VIDEO);	TTF_Init();
SDL_Window   *window =SDL_CreateWindow("Of Glass And Steel",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		600, 400,
		SDL_WINDOW_SHOWN |SDL_WINDOW_RESIZABLE);
SDL_Renderer *renderer =SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED);

//loading menus
Menu* menu_title	=load_menu_title(renderer);
Menu* menu_new_game	=load_menu_new_game(renderer);
Menu* menu_load_game	=load_menu_load_game(renderer);
//running menus
Menu_return menu_return =menu_loop(renderer, window, menu_title);
while(menu_return.type!='q' && menu_return.type!='g'){
switch(menu_return.type){
case 'm': switch(menu_return.info){
	case 't':
		menu_return =menu_loop(renderer,window,menu_title);
			break;
	case 'n':
		menu_return =menu_loop(renderer,window,menu_new_game);
			break;
	case 'l':
		menu_return =menu_loop(renderer,window,menu_load_game);
			break;
	default:	break;}	break;
default:			break;}}
//unloading menus
free_menu(menu_title);
free_menu(menu_new_game);
free_menu(menu_load_game);

//starting game
if(menu_return.type=='g'){ switch(menu_return.info){
case 'n':	new_game(renderer, window);	break;
case 'l':	load_game(renderer, window);	break;
default:					break;}}

//SDL end
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();
return 0;}

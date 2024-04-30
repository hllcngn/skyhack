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

//loading menus
Menu* menu_title =load_menu_title(renderer);
Menu* menu_new_game =load_menu_new_game(renderer);
Menu* menu_load_game =load_menu_load_game(renderer);

//run title menu
int stop =0; int result =0;
Menu_return* menu_return =menu_loop(renderer, window, menu_title);
while(menu_return->type!='q'){ switch(menu_return->type){
case 'm':
		menu_return =menu_loop(renderer,window,menu_new_game);
		break;
/*case 'l':	int load_return =menu_loop(renderer, window, menu_load_game);
		if(load_return=='q') stop++;	break;
		if(load_return!='b') stop++; result =156;	break;
		break;
case 'n':	int new_return =menu_loop(renderer, window, menu_new_game);
		if(new_return=='q') stop++;	break;
		if(new_return!='b') stop++; result =264;	break;
		break;
case 'q':	stop++;	break;
*/
default:	break;}
}
free_menu(menu_title);
free_menu(menu_new_game);
free_menu(menu_load_game);

//SDL end
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();
return 0;}

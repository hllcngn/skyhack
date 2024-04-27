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

//loading/creating title menu assets
T_menu* t_menu_title =load_menu_title(renderer);

//title screen loop
int select =0;
draw_menu_title(window, renderer, t_menu_title, select);
SDL_RenderPresent(renderer);
int terminate =0;
SDL_Event e;
while(!terminate){

//event handling
while(SDL_PollEvent(&e)){
if (e.type ==SDL_QUIT)
	terminate++;
else if (e.type ==SDL_WINDOWEVENT) switch(e.window.event){
	case SDL_WINDOWEVENT_RESIZED:
		draw_menu_title(window, renderer, t_menu_title, select);
		SDL_RenderPresent(renderer);
						break;
	default:				break;}
else if (e.type ==SDL_KEYDOWN) switch(e.key.keysym.sym){
	case SDLK_UP:	{int options_nb =t_menu_title->options_nb;
			if(select) select--;
			else select =options_nb-1;}
		draw_menu_title(window, renderer, t_menu_title, select);
		SDL_RenderPresent(renderer);
						break;
	case SDLK_DOWN:	{int options_nb =t_menu_title->options_nb;
			if(select<options_nb-1) select++;
			else select =0;}
		draw_menu_title(window, renderer, t_menu_title, select);
		SDL_RenderPresent(renderer);
						break;
	case K_TITLE_QUIT:	terminate++;	break;
	case K_TITLE_SETT: //open settings menu loop
						break;
	case K_TITLE_NEW: //end title loop, launch game
	case K_TITLE_LOAD:			break;
	default:				break;}}
}//end of title screen loop

//SDL cleaning
free_menu_title(t_menu_title);
//SDL end
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();
return 0;}

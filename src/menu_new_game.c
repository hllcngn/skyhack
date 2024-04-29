#include "ogns.h"

int menu_new_game(SDL_Renderer* renderer, SDL_Window* window){
T_menu* t_menu_new_game =load_menu_new_game(renderer);
clear_window(renderer, BLACK);

//title screen loop
int select =0;
draw_menu_new_game(window, renderer, t_menu_new_game, select);
SDL_RenderPresent(renderer); //shouldnt be there
int terminate =0;
SDL_Event e;
while(!terminate){

//event handling
while(SDL_PollEvent(&e)){
if (e.type ==SDL_QUIT)
	terminate++;
else if (e.type ==SDL_WINDOWEVENT) switch(e.window.event){
	case SDL_WINDOWEVENT_RESIZED:
		draw_menu_new_game(window, renderer, t_menu_new_game, select);
		SDL_RenderPresent(renderer);
						break;
	default:				break;}
else if (e.type ==SDL_KEYDOWN) switch(e.key.keysym.sym){
	case SDLK_UP:	{int options_nb =t_menu_new_game->options_nb;
			if(select) select--;
			else select =options_nb-1;}
		draw_menu_new_game(window, renderer, t_menu_new_game, select);
		SDL_RenderPresent(renderer);
						break;
	case SDLK_DOWN:	{int options_nb =t_menu_new_game->options_nb;
			if(select<options_nb-1) select++;
			else select =0;}
		draw_menu_new_game(window, renderer, t_menu_new_game, select);
		SDL_RenderPresent(renderer);
						break;
	case SDLK_q:	terminate++;		break;
	case SDLK_s: //open settings menu loop
			return('s');
						break;
	case SDLK_n: //end title loop, launch game
			return('n');
	case SDLK_l:	return('l');		break;
	default:				break;}}
}//end of title screen loop

//cleaning
//free_menu_new_game(t_menu_new_game);

if(terminate)	return('q');
return -1;}

T_menu* load_menu_new_game(SDL_Renderer* renderer){
TTF_Font* font =TTF_OpenFont("ass/TimesNewRoman.ttf",18);
int options_nb =5;
SDL_Texture** t_options =malloc(sizeof(SDL_Texture*)*options_nb);

SDL_Surface* s_option =SDL_LoadBMP("ass/title1.bmp");
t_options[0] =SDL_CreateTextureFromSurface(renderer, s_option);
SDL_FreeSurface(s_option);
s_option =TTF_RenderText_Blended_Wrapped(font,
		"Please adjust the size of the skyscrapper.\n\
The game will take up the whole window.\n\
Larger floors = more difficulty\n\
= taller building = more levels = more difficulty", RED, 350);
t_options[1] =SDL_CreateTextureFromSurface(renderer, s_option);
SDL_FreeSurface(s_option);
s_option =TTF_RenderText_Blended_Wrapped(font, "o Adjust window size\n\
(Larger window = larger floors)", RED, 250);
t_options[2] =SDL_CreateTextureFromSurface(renderer, s_option);
SDL_FreeSurface(s_option);
s_option =TTF_RenderText_Blended_Wrapped(font, "o Adjust zoom:  <  x1  >\n\
(Smaller zoom = larger floors)", RED, 250);
t_options[3] =SDL_CreateTextureFromSurface(renderer, s_option);
SDL_FreeSurface(s_option);
s_option = SDL_LoadBMP("ass/button-enter1.bmp");
t_options[4] =SDL_CreateTextureFromSurface(renderer, s_option);
SDL_FreeSurface(s_option);
T_menu* t_menu =malloc(sizeof(T_menu));
t_menu->t_title		=NULL;
t_menu->t_options	=t_options;
t_menu->t_select	=NULL;
t_menu->options_nb	=options_nb;
return t_menu;}


void draw_menu_new_game(SDL_Window* window, SDL_Renderer* renderer,
		T_menu* t_menu, int select){
SDL_Texture* t_title	=NULL;
SDL_Texture** t_options	=t_menu->t_options;
SDL_Texture** t_select	=NULL;
int options_nb		=t_menu->options_nb;
//background
clear_window(renderer, BLACK);
//options
int w,h; SDL_GetWindowSize(window, &w,&h);
int y =h/4.2;
for(int i=0;i<options_nb;i++){
	int w1,h1; SDL_QueryTexture(t_options[i],NULL,NULL,&w1,&h1);
	SDL_Rect r_option =(SDL_Rect){(w-350)/2+10, y, w1,h1};
	SDL_RenderCopy(renderer, t_options[i], NULL, &r_option);
	y+=h1+10;}
	//if (i==select)	SDL_RenderCopy(renderer, t_select[i], NULL, &r_option);
	//else		SDL_RenderCopy(renderer, t_options[i], NULL, &r_option);}
return;}

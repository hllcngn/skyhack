#include "ogns.h"

//running the title menu
int menu_title(SDL_Renderer* renderer, SDL_Window* window){
//loading/creating title menu assets
T_menu* t_menu_title =load_menu_title(renderer);

//title screen loop
int select =0;
draw_menu_title(window, renderer, t_menu_title, select);
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
free_menu_title(t_menu_title);

if(terminate)	return('q');
return -1;}


//loading/creating title menu assets
T_menu* load_menu_title(SDL_Renderer* renderer){
SDL_Surface *s_title =SDL_LoadBMP("ass/title1.bmp");
SDL_Texture *t_title =SDL_CreateTextureFromSurface(renderer, s_title);
SDL_FreeSurface(s_title);
TTF_Font* font =TTF_OpenFont("ass/TimesNewRoman.ttf",22);
int options_nb =4;
SDL_Texture** t_options =malloc(sizeof(SDL_Texture*)*options_nb);
SDL_Surface* s_option =TTF_RenderText_Solid(font,
		">   New Game ....................... (N)", RED);
t_options[0] =SDL_CreateTextureFromSurface(renderer, s_option);
SDL_FreeSurface(s_option);
s_option =TTF_RenderText_Solid(font,
		">   Load Game ....................... (L)", RED);
t_options[1] =SDL_CreateTextureFromSurface(renderer, s_option);
SDL_FreeSurface(s_option);
s_option =TTF_RenderText_Solid(font,
		">   Settings ............................. (S)", RED);
t_options[2] =SDL_CreateTextureFromSurface(renderer, s_option);
SDL_FreeSurface(s_option);
s_option =TTF_RenderText_Solid(font,
		">   Quit .................................. (Q)", RED);
t_options[3] =SDL_CreateTextureFromSurface(renderer, s_option);
SDL_FreeSurface(s_option);
SDL_Texture** t_select =malloc(sizeof(SDL_Texture*)*options_nb);
s_option =TTF_RenderText_Solid(font,
		">   New Game ....................... (N)", LIGHTBLUE);
t_select[0] =SDL_CreateTextureFromSurface(renderer, s_option);
SDL_FreeSurface(s_option);
s_option =TTF_RenderText_Solid(font,
		">   Load Game ....................... (L)", LIGHTBLUE);
t_select[1] =SDL_CreateTextureFromSurface(renderer, s_option);
SDL_FreeSurface(s_option);
s_option =TTF_RenderText_Solid(font,
		">   Settings ............................. (S)", LIGHTBLUE);
t_select[2] =SDL_CreateTextureFromSurface(renderer, s_option);
SDL_FreeSurface(s_option);
s_option =TTF_RenderText_Solid(font,
		">   Quit .................................. (Q)", LIGHTBLUE);
t_select[3] =SDL_CreateTextureFromSurface(renderer, s_option);
SDL_FreeSurface(s_option);
T_menu* t_menu =malloc(sizeof(T_menu));
t_menu->t_title		=t_title;
t_menu->t_options	=t_options;
t_menu->t_select	=t_select;
t_menu->options_nb	=options_nb;
return t_menu;}


void free_menu_title(T_menu* t_menu){
SDL_Texture* t_title	=t_menu->t_title;
SDL_Texture** t_options	=t_menu->t_options;
SDL_Texture** t_select	=t_menu->t_select;
int options_nb		=t_menu->options_nb;
SDL_DestroyTexture(t_title);
for(int i=0;i<options_nb;i++) SDL_DestroyTexture(t_options[i]);
	free(t_options);
for(int i=0;i<options_nb;i++) SDL_DestroyTexture(t_select[i]);
	free(t_select);
return;}


void draw_menu_title(SDL_Window* window, SDL_Renderer* renderer,
		T_menu* t_menu, int select){
SDL_Texture* t_title	=t_menu->t_title;
SDL_Texture** t_options	=t_menu->t_options;
SDL_Texture** t_select	=t_menu->t_select;
int options_nb		=t_menu->options_nb;
//background
clear_window(renderer, DARKBLUE);
//title
int w,h; SDL_GetWindowSize(window, &w,&h);
SDL_Rect r_title =(SDL_Rect){(w-350)/2, h/4.2, 350,50};
SDL_RenderCopy(renderer, t_title, NULL, &r_title);
//options
for(int i=0;i<options_nb;i++){
	int w1,h1; SDL_QueryTexture(t_options[i],NULL,NULL,&w1,&h1);
	SDL_Rect r_option =(SDL_Rect){(w-350)/2+10, r_title.y+70+i*40, w1,h1};
	if (i==select)	SDL_RenderCopy(renderer, t_select[i], NULL, &r_option);
	else		SDL_RenderCopy(renderer, t_options[i], NULL, &r_option);}
return;}

#include "ogns.h"

void menu_new_game(SDL_Renderer* renderer, SDL_Window* window){
T_menu* t_menu_new_game =load_menu_new_game(renderer);
clear_window(renderer, BLACK);
return;}

T_menu* load_menu_new_game(SDL_Renderer* renderer){
TTF_Font* font =TTF_OpenFont("ass/TimesNewRoman.ttf",18);
int options_nb =7;
SDL_Texture** t_options =malloc(sizeof(SDL_Texture*)*options_nb);

SDL_Surface* s_option =SDL_LoadBMP("ass/title1.bmp");
t_options[0] =SDL_CreateTextureFromSurface(renderer, s_option);
SDL_FreeSurface(s_option);
s_option =TTF_RenderText_Solid(font,
		"Please adjust the size of the skyscrapper.\n
		The game will take up the whole window.\n
		Larger floors = taller building = more levels", RED);
t_options[1] =SDL_CreateTextureFromSurface(renderer, s_option);
SDL_FreeSurface(s_option);
s_option =TTF_RenderText_Solid("o Adjust window size\n
				(Larger window = larger floors)", RED);
t_options[2] =SDL_CreateTextureFromSurface(renderer, s_option);
SDL_FreeSurface(s_option);
s_option =TTF_RenderText_Solid("o Adjust zoom:  <  x1  >\n
				(Smaller zoom = larger floors)", RED);
t_options[2] =SDL_CreateTextureFromSurface(renderer, s_option);
SDL_FreeSurface(s_option);
s_option = SDL_LoadBMP("ass/button-enter1.bmp");

#include "ogns.h"

T_menu* load_menu_new_game(SDL_Renderer* renderer){
int items_nb =5;
menu_item** items =malloc(sizeof(menu_item*)*items_nb);
for(int i=0; i<items_nb; i++) items[i] =malloc(sizeof(menu_item));
TTF_Font* font =TTF_OpenFont("ass/TimesNewRoman.ttf",18);

SDL_Surface* s_item =SDL_LoadBMP("ass/title1.bmp");
items[0]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[0]->align_right = items[0]->k =0;
items[0]->t_select =NULL;

s_item =TTF_RenderText_Blended_Wrapped(font,
		"Please adjust the size of the skyscrapper.\n\
The game will take up the whole window.\n\
Larger floors = more difficulty\n\
= taller building = more levels = more difficulty", RED, 350);
items[1]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[1]->align_right = items[1]->k =0;
items[1]->t_select =NULL;

s_item =TTF_RenderText_Blended_Wrapped(font, "o Adjust window size\n\
(Larger window = larger floors)", RED, 250);
items[2]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[2]->align_right = items[2]->k =0;
items[2]->t_select =NULL;

s_item =TTF_RenderText_Blended_Wrapped(font, "o Adjust zoom:  <  x1  > (Z)\n\
(Smaller zoom = larger floors)", RED, 250);
items[3]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
s_item =TTF_RenderText_Blended_Wrapped(font, "o Adjust zoom:  <  x1  > (Z)\n\
(Smaller zoom = larger floors)", LIGHTBLUE, 250);
items[3]->t_select =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[3]->align_right =0;
items[3]->k =SDLK_z;

s_item =SDL_LoadBMP("ass/button-enter1.bmp");
items[4]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
s_item =SDL_LoadBMP("ass/button-enter1-selected.bmp");
items[4]->t_select =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[4]->align_right =1;
items[4]->k =SDLK_RETURN;

T_menu* t_menu =malloc(sizeof(T_menu));
t_menu->items		=items;
t_menu->items_nb	=items_nb;
t_menu->bgcolor		=BLACK;
return t_menu;}

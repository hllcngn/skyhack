#include "ogns.h"

T_menu* load_menu_title(SDL_Renderer* renderer){
int items_nb =5;
menu_item** items =malloc(sizeof(menu_item*)*items_nb);
for(int i=0; i<items_nb; i++) items[i] =malloc(sizeof(menu_item));
TTF_Font* font =TTF_OpenFont("ass/TimesNewRoman.ttf",22);

int n =0;
SDL_Surface *s_item =SDL_LoadBMP("ass/title1.bmp");
items[n]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[n]->t_select =NULL;
items[n]->align_right = items[n]->k =0;
n++;

s_item =TTF_RenderText_Solid(font,
		">   New Game ....................... (N)", RED);
items[n]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
s_item =TTF_RenderText_Solid(font,
		">   New Game ....................... (N)", LIGHTBLUE);
items[n]->t_select =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[n]->align_right =0;
items[n]->k ='n';
n++;

s_item =TTF_RenderText_Solid(font,
		">   Load Game ....................... (L)", RED);
items[n]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
s_item =TTF_RenderText_Solid(font,
		">   Load Game ....................... (L)", LIGHTBLUE);
items[n]->t_select =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[n]->align_right =0;
items[n]->k ='l';
n++;

s_item =TTF_RenderText_Solid(font,
		">   Settings ............................. (S)", RED);
items[n]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
s_item =TTF_RenderText_Solid(font,
		">   Settings ............................. (S)", LIGHTBLUE);
items[n]->t_select =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[n]->align_right =0;
items[n]->k ='s';
n++;

s_item =TTF_RenderText_Solid(font,
		">   Quit .................................. (Q)", RED);
items[n]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
s_item =TTF_RenderText_Solid(font,
		">   Quit .................................. (Q)", LIGHTBLUE);
items[n]->t_select =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[n]->align_right =0;
items[n]->k ='q';

T_menu* t_menu =malloc(sizeof(T_menu));
t_menu->items		=items;
t_menu->items_nb	=items_nb;
t_menu->bgcolor		=DARKBLUE;
return t_menu;}

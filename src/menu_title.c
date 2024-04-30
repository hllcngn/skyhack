#include "ogns.h"

Menu* load_menu_title(SDL_Renderer* renderer){
int items_nb =5;
Menu_item** items =malloc(sizeof(Menu_item*)*items_nb);
for(int i=0; i<items_nb; i++) items[i] =malloc(sizeof(Menu_item));
TTF_Font* font =TTF_OpenFont("ass/TimesNewRoman.ttf",22);
int n =0; SDL_Surface* s_item;

s_item =SDL_LoadBMP("ass/title1.bmp");
items[n]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[n]->t_select =NULL;
items[n]->align = items[n]->k =0; items[n]->ret =(Menu_return){0,0};
n++;

s_item =TTF_RenderText_Solid(font,
		">   New Game ....................... (N)", RED);
items[n]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
s_item =TTF_RenderText_Solid(font,
		">   New Game ....................... (N)", LIGHTBLUE);
items[n]->t_select =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[n]->align =0;
items[n]->k ='n'; items[n]->ret =(Menu_return){'m','n'};
n++;

s_item =TTF_RenderText_Solid(font,
		">   Load Game ....................... (L)", RED);
items[n]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
s_item =TTF_RenderText_Solid(font,
		">   Load Game ....................... (L)", LIGHTBLUE);
items[n]->t_select =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[n]->align =0;
items[n]->k ='l'; items[n]->ret =(Menu_return){'m','l'};
n++;

s_item =TTF_RenderText_Solid(font,
		">   Settings ............................. (S)", RED);
items[n]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
s_item =TTF_RenderText_Solid(font,
		">   Settings ............................. (S)", LIGHTBLUE);
items[n]->t_select =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[n]->align =0;
items[n]->k ='s'; items[n]->ret =(Menu_return){'m','s'};
n++;

s_item =TTF_RenderText_Solid(font,
		">   Quit .................................. (Q)", RED);
items[n]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
s_item =TTF_RenderText_Solid(font,
		">   Quit .................................. (Q)", LIGHTBLUE);
items[n]->t_select =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[n]->align =0;
items[n]->k ='q'; items[n]->ret =(Menu_return){'q',0};

Menu* menu =malloc(sizeof(Menu));
menu->items	=items;
menu->items_nb	=items_nb;
menu->bgcolor	=DARKBLUE;
return menu;}

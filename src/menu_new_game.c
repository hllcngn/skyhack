#include "ogns.h"

Menu* load_menu_new_game(SDL_Renderer* renderer){
int items_nb =5;
Menu_item** items =malloc(sizeof(Menu_item*)*items_nb);
for(int i=0; i<items_nb; i++) items[i] =malloc(sizeof(Menu_item));
TTF_Font* font =TTF_OpenFont("ass/TimesNewRoman.ttf",18);
int n =0; SDL_Surface* s_item;

s_item =SDL_LoadBMP("ass/title1.bmp");
items[n]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[n]->align = items[n]->k =0; items[n]->ret =(Menu_return){0,0};
items[n]->t_select =NULL;
n++;

s_item =TTF_RenderText_Blended_Wrapped(font,
		"Please adjust the size of the skyscrapper.\n\
The game will take up the whole window.\n\
Larger window = larger floors = more difficulty\n\
= taller building = more levels = more difficulty", RED, 370);
items[n]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[n]->align = items[n]->k =0; items[n]->ret =(Menu_return){0,0};
items[n]->t_select =NULL;
n++;

s_item =TTF_RenderText_Blended_Wrapped(font, "o Adjust window size\n\
(Larger window = larger floors)", RED, 250);
items[n]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[n]->align = items[n]->k =0; items[n]->ret =(Menu_return){0,0};
items[n]->t_select =NULL;
n++;

s_item =TTF_RenderText_Blended_Wrapped(font, "o Adjust zoom:  <  x1  > (Z)\n\
(Smaller zoom = larger floors)", RED, 250);
items[n]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
s_item =TTF_RenderText_Blended_Wrapped(font, "o Adjust zoom:  <  x1  > (Z)\n\
(Smaller zoom = larger floors)", LIGHTBLUE, 250);
items[n]->t_select =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[n]->align =0;
items[n]->k =SDLK_z; items[n]->ret =(Menu_return){0,0};
n++;

s_item =SDL_LoadBMP("ass/button-enter1.bmp");
items[n]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
s_item =SDL_LoadBMP("ass/button-enter1-selected.bmp");
items[n]->t_select =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[n]->align =ALIGN_RIGHT;
items[n]->k =SDLK_RETURN; items[n]->ret =(Menu_return){'g','n'};

Menu* menu =malloc(sizeof(Menu));
menu->items	=items;
menu->items_nb	=items_nb;
menu->bgcolor	=BLACK;
return menu;}

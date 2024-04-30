#include "ogns.h"

Menu* load_menu_load_game(SDL_Renderer* renderer){
int items_nb =3;
Menu_item** items =malloc(sizeof(Menu_item*)*items_nb);
for(int i=0; i<items_nb; i++) items[i] =malloc(sizeof(Menu_item));
TTF_Font* font =TTF_OpenFont("ass/TimesNewRoman.ttf",26);
int n =0; SDL_Surface* s_item;

s_item =TTF_RenderText_Blended(font, "Load game", RED);
items[n]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[n]->align = items[n]->k =0; items[n]->ret =(Menu_return){0,0};
items[n]->t_select =NULL;
n++;

s_item =SDL_CreateRGBSurface(0, 300,200, 32,0,0,0,0);
SDL_Rect r =(SDL_Rect){0,0,300,200};
SDL_FillRect(s_item, &r, 79);
items[n]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[n]->align =ALIGN_CENTER;
items[n]->k =0; items[n]->ret =(Menu_return){'g','l'};
items[n]->t_select =NULL;
n++;

s_item =SDL_LoadBMP("ass/button-back1.bmp");
items[n]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
s_item =SDL_LoadBMP("ass/button-back1-selected.bmp");
items[n]->t_select =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[n]->align =ALIGN_CENTER;
items[n]->k ='b'; items[n]->ret =(Menu_return){'m','t'};

Menu* menu =malloc(sizeof(Menu));
menu->items	=items;
menu->items_nb	=items_nb;
menu->bgcolor	=DARKBLUE;
return menu;}

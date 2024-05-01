#include "ogns.h"

Menu* load_menu_title(SDL_Renderer* renderer){
int items_nb =4;
Menu_item** items =malloc(sizeof(Menu_item*)*items_nb);
for(int i=0; i<items_nb; i++) items[i] =malloc(sizeof(Menu_item));
TTF_Font* font =TTF_OpenFont("ass/arial-monospaced-mt.ttf",22);
int char_w, char_h; TTF_SizeText(font, "c", &char_w,&char_h);
int n =0; SDL_Surface* s_item;

s_item =SDL_LoadBMP("ass/title.bmp");
items[n]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[n]->t_select =NULL;
items[n]->align = items[n]->k =0; items[n]->ret =(Menu_return){0,0};
n++;

s_item =TTF_RenderText_Blended(font, ">  New game", RED);
items[n]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
SDL_SetRenderTarget(renderer, items[n]->t);
SDL_SetRenderDrawColor(renderer, 255,0,0,0xFF);
SDL_RenderDrawLine(renderer, 0,0,1000,1000);//char_w*3,char_h-5, char_w*4,char_h-5);
SDL_SetRenderTarget(renderer, NULL);
s_item =TTF_RenderText_Blended(font, ">  New game", LIGHTBLUE);
items[n]->t_select =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[n]->align =0;
items[n]->k ='n'; items[n]->ret =(Menu_return){'m','n'};
n++;

s_item =TTF_RenderText_Blended(font, ">  Load game", RED);
items[n]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
s_item =TTF_RenderText_Blended(font, ">  Load game", LIGHTBLUE);
items[n]->t_select =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[n]->align =0;
items[n]->k ='l'; items[n]->ret =(Menu_return){'m','l'};
n++;

s_item =TTF_RenderText_Blended(font, ">  Quit", RED);
items[n]->t =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
s_item =TTF_RenderText_Blended(font, ">  Quit", LIGHTBLUE);
items[n]->t_select =SDL_CreateTextureFromSurface(renderer, s_item);
SDL_FreeSurface(s_item);
items[n]->align =0;
items[n]->k ='q'; items[n]->ret =(Menu_return){'q',0};

Menu* menu =malloc(sizeof(Menu));
menu->items	=items;
menu->items_nb	=items_nb;
menu->bgcolor	=DARKBLUE;
return menu;}

#pragma once
#include "ogns.h"

typedef struct{
	SDL_Texture* t_title;
	SDL_Texture** t_options;
	SDL_Texture** t_select;
	int options_nb;			}T_menu;


int menu_title(SDL_Renderer*, SDL_Window*);
T_menu* load_menu_title(SDL_Renderer*);//loading/creating title menu assets
void free_menu_title(T_menu*);
void draw_menu_title(SDL_Window*, SDL_Renderer*, T_menu*, int select);


#pragma once
#include "ogns.h"

typedef struct{
	SDL_Texture*	tex;
	int		align_right;
	SDL_Texture*	t_select;
	SDL_Keycode	key;		}menu_item;

typedef struct{
	SDL_Texture*	t_title;
	SDL_Texture**	t_options;
	menu_item**	items;
	SDL_Texture**	t_select;
	int		options_nb;	}T_menu;


int select_previous_menu_item(T_menu* t_menu, int* sel);
int select_next_menu_item(T_menu* t_menu, int* sel);


int menu_title(SDL_Renderer*, SDL_Window*);
T_menu* load_menu_title(SDL_Renderer*);//loading/creating title menu assets
void free_menu_title(T_menu*);
void draw_menu_title(SDL_Window*, SDL_Renderer*, T_menu*, int select);

int menu_new_game(SDL_Renderer*, SDL_Window*);
T_menu* load_menu_new_game(SDL_Renderer*);
void draw_menu_new_game(SDL_Window*, SDL_Renderer*, T_menu*, int select);

#pragma once
#include "ogns.h"

typedef struct{
	SDL_Texture*	t;
	int		align_right;
	SDL_Texture*	t_select;
	SDL_Keycode	k;		}menu_item;

typedef struct{
	menu_item**	items;
	int		items_nb;
	SDL_Color	bgcolor;	}T_menu;


int select_previous_menu_item(T_menu* t_menu, int* sel);
int select_next_menu_item(T_menu* t_menu, int* sel);
void free_menu(T_menu* t_menu);
void draw_menu(SDL_Window* window, SDL_Renderer* renderer,
		T_menu* t_menu, int select);
int menu_loop(SDL_Renderer* renderer, SDL_Window* window, T_menu* t_menu);


T_menu* load_menu_title(SDL_Renderer*);
T_menu* load_menu_new_game(SDL_Renderer*);

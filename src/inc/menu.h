#pragma once
#include "ogns.h"

#define ALIGN_LEFT	1
#define ALIGN_CENTER	2
#define ALIGN_RIGHT	3

typedef struct{
	int		type;
	int		info;		}Menu_return;

typedef struct{
	SDL_Texture*	t;
	int		align;
	SDL_Texture*	t_select;
	SDL_Keycode	k;
	Menu_return	ret;		}Menu_item;

typedef struct{
	Menu_item**	items;
	int		items_nb;
	SDL_Color	bgcolor;	}Menu;


int select_previous_menu_item(Menu* menu, int* sel);
int select_next_menu_item(Menu* menu, int* sel);
void free_menu(Menu* menu);
void draw_menu(SDL_Window* window, SDL_Renderer* renderer,
		Menu* menu, int select);
Menu_return menu_loop(SDL_Renderer* renderer, SDL_Window* window,
		Menu* menu);


Menu* load_menu_title(SDL_Renderer*);
Menu* load_menu_new_game(SDL_Renderer*);
Menu* load_menu_load_game(SDL_Renderer*);

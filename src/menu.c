#include "ogns.h"

int select_previous_menu_item(T_menu* t_menu, int* sel){
int select =*sel;
if(select) select--;
else select =t_menu->items_nb-1;
int i=0;
for(;!t_menu->items[select]->t_select && i<t_menu->items_nb; i++){
	if(select) select--;
	else select =t_menu->items_nb-1;}
if(i==t_menu->items_nb) return -1;
*sel =select;	return 0;}

int select_next_menu_item(T_menu* t_menu, int* sel){
int select =*sel;
if(select<t_menu->items_nb-1) select++;
else select =0;
int i=0;
for(;!t_menu->items[select]->t_select && i<t_menu->items_nb; i++){
	if(select<t_menu->items_nb-1) select++;
	else select =0;}
if(i==t_menu->items_nb) return -1;
*sel =select;	return 0;}


void free_menu(T_menu* t_menu){
menu_item** items	=t_menu->items;
int items_nb		=t_menu->items_nb;
for(int i=0;i<items_nb;i++){
	SDL_DestroyTexture(items[i]->t);
	if(items[i]->t_select) SDL_DestroyTexture(items[i]->t_select);}
free(items);
free(t_menu);
return;}


void draw_menu(SDL_Window* window, SDL_Renderer* renderer,
		T_menu* t_menu, int select){
menu_item** items	=t_menu->items;
int items_nb		=t_menu->items_nb;
//background
clear_window(renderer, t_menu->bgcolor);
//items
int w,h; SDL_GetWindowSize(window, &w,&h);
int y =h/5;
for(int i=0;i<items_nb;i++){
	int wt,ht; SDL_QueryTexture(items[i]->t,NULL,NULL,&wt,&ht);
	SDL_Rect r_item =(SDL_Rect){(w-350)/2, y, wt,ht};
	if (i==select && items[i]->t_select)
		SDL_RenderCopy(renderer, items[i]->t_select, NULL, &r_item);
	else	SDL_RenderCopy(renderer, items[i]->t, NULL, &r_item);
	y+=ht+10;}
return;}


int menu_loop(SDL_Renderer* renderer, SDL_Window* window, T_menu* t_menu){
int select =0;
for(int i=0; i<t_menu->items_nb; i++)
	if(t_menu->items[i]->t_select){ select =i; break;}
draw_menu(window, renderer, t_menu, select);
SDL_RenderPresent(renderer);
int terminate =0;
SDL_Event e;
while(!terminate){

//event handling
while(SDL_PollEvent(&e)){
if (e.type ==SDL_QUIT)
	terminate++;
else if (e.type ==SDL_WINDOWEVENT) switch(e.window.event){
	case SDL_WINDOWEVENT_RESIZED:
		draw_menu(window, renderer, t_menu, select);
		SDL_RenderPresent(renderer);		break;
	default:					break;}
else if (e.type ==SDL_KEYDOWN) switch(e.key.keysym.sym){
	case SDLK_UP:
		if(!select_previous_menu_item(t_menu, &select)){
			draw_menu(window, renderer, t_menu, select);
			SDL_RenderPresent(renderer);}	break;
	case SDLK_DOWN:
		if(!select_next_menu_item(t_menu, &select)){
			draw_menu(window, renderer, t_menu, select);
			SDL_RenderPresent(renderer);}
							break;
	case SDLK_q:	terminate++;			break;
	case SDLK_s: //open settings menu loop
			return('s');
							break;
	case SDLK_n: //end title loop, launch game
			return('n');
	case SDLK_l:	return('l');			break;
	default:					break;}}
}//end of title screen loop
if(terminate)	return('q');
return -1;}

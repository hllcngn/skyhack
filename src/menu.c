#include "ogns.h"

int select_previous_menu_item(Menu* menu, int* sel){
int select =*sel;
if(select) select--;
else select =menu->items_nb-1;
int i=0;
for(;!menu->items[select]->t_select && i<menu->items_nb; i++){
	if(select) select--;
	else select =menu->items_nb-1;}
if(i==menu->items_nb) return -1;
*sel =select;	return 0;}

int select_nexmenu_item(Menu* menu, int* sel){
int select =*sel;
if(select<menu->items_nb-1) select++;
else select =0;
int i=0;
for(;!menu->items[select]->t_select && i<menu->items_nb; i++){
	if(select<menu->items_nb-1) select++;
	else select =0;}
if(i==menu->items_nb) return -1;
*sel =select;	return 0;}


void free_menu(Menu* menu){
Menu_item** items	=menu->items;
int items_nb		=menu->items_nb;
for(int i=0;i<items_nb;i++){
	SDL_DestroyTexture(items[i]->t);
	if(items[i]->t_select) SDL_DestroyTexture(items[i]->t_select);}
free(items);
free(menu);
return;}


void draw_menu(SDL_Window* window, SDL_Renderer* renderer,
		Menu* menu, int select){
Menu_item** items	=menu->items;
int items_nb		=menu->items_nb;
//background
clear_window(renderer, menu->bgcolor);
//items
int w,h; SDL_GetWindowSize(window, &w,&h);
int y =h/5;
for(int i=0;i<items_nb;i++){
	int wt,ht; SDL_QueryTexture(items[i]->t,NULL,NULL,&wt,&ht);
	SDL_Rect r_item =(SDL_Rect){(w-350)/2, y, wt,ht};
	if(items[i]->align==ALIGN_RIGHT) r_item.x =(w+350)/2-wt;
	if(i==select && items[i]->t_select)
		SDL_RenderCopy(renderer, items[i]->t_select, NULL, &r_item);
	else	SDL_RenderCopy(renderer, items[i]->t, NULL, &r_item);
	y+=ht+10;}
return;}


//return a function pointer?
Menu_return menu_loop(SDL_Renderer* renderer, SDL_Window* window, Menu* menu){
//Menu_return* ret =calloc(sizeof(Menu_return), 1);
int select =0;
for(int i=0; i<menu->items_nb; i++)
	if(menu->items[i]->t_select){ select =i; break;}
draw_menu(window, renderer, menu, select);
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
		draw_menu(window, renderer, menu, select);
		SDL_RenderPresent(renderer);		break;
	default:					break;}
else if (e.type ==SDL_KEYDOWN) switch(e.key.keysym.sym){
	case SDLK_UP:
		if(!select_previous_menu_item(menu, &select)){
			draw_menu(window, renderer, menu, select);
			SDL_RenderPresent(renderer);}	break;
	case SDLK_DOWN:
		if(!select_nexmenu_item(menu, &select)){
			draw_menu(window, renderer, menu, select);
			SDL_RenderPresent(renderer);}
							break;
	case SDLK_q:	terminate++;			break;
	default:
		int i; for(i=0; i<menu->items_nb
				&& e.key.keysym.sym!=menu->items[i]->k; i++);
		if(i<menu->items_nb)
			return menu->items[i]->ret;
							break;}}
}//end of title screen loop
Menu_return ret;
if(terminate){ ret.type ='q'; return(ret);}
ret.type =-1; return(ret);}

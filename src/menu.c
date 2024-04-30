#include "ogns.h"

int select_previous_menu_item(T_menu* t_menu, int* sel){
int select =*sel;
if(select) select--;
else select =t_menu->options_nb-1;
int i=0;
for(;!t_menu->items[select]->t_select && i<t_menu->options_nb; i++){
	if(select) select--;
	else select =t_menu->options_nb-1;}
if(i==t_menu->options_nb) return -1;
*sel =select;	return 0;}

int select_next_menu_item(T_menu* t_menu, int* sel){
int select =*sel;
if(select<t_menu->options_nb-1) select++;
else select =0;
int i=0;
for(;!t_menu->items[select]->t_select && i<t_menu->options_nb; i++){
	if(select<t_menu->options_nb-1) select++;
	else select =0;}
if(i==t_menu->options_nb) return -1;
*sel =select;	return 0;}

#include "debug.h"
#include <stdlib.h>

Debug	*debug_init(void){
Debug	*new =(Debug*)malloc(sizeof(Debug));
new->w =newwin(WDBGH,WDBGW, WDBGY,WDBGX);
new->on =0;
debug_log(new, "* debug start *"); return new;}

void	debug_end(Debug *d){
debug_log(d, "* debug end *");
delwin(d->w);
free(d); return;}

void	display_debug(Debug *d){ //this is not going to work
d->on =1; wrefresh(d->w); return;} //if we erase what we previously printed
void	undisplay_debug(Debug *d){ //without saving it
d->on =0; werase(d->w); wrefresh(d->w); return;} //or is it intended behavior

void	debug_log(Debug *d, const char *str){
waddch(d->w, '\n'); wprintw(d->w, str);
if (d->on) wrefresh(d->w); return;}

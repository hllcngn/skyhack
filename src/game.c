#include "h.h"

int	game(GAME* gm){
vect	pos= gm->pos;
char*	clsn= gm->clsn;
buf1	b1 = gm->b1;
WINDOW* wd = newwin(8, 15, 0,COLS-15);

char k= 0; while(k= getch()){ switch(k){
case K_QUIT:				return 0;

case ']':	//draw a random room
	make_level(clsn, b1);		break;
case '\\':	//debug
	wclear(wd);
	debug_buf(wd, b1);
	debug_seed(wd); wrefresh(wd); getch();
	make_level(clsn, b1); refresh();
	break;

case K_UP:
case K_DOWN:
case K_LEFT:
case K_RIGHT:
case K_UP_LEFT:
case K_UP_RIGHT:
case K_DOWN_LEFT:
case K_DOWN_RIGHT:
	//character & floor tile are redrawn inside of this function
	player_move(k, &pos, clsn);	break;

default:				break;}}
return 0;}

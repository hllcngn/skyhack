#include "h.h"

int	game(GAME* gm){
vect	pos= gm->pos;
char*	clsn= gm->clsn;
buf1	b1 = gm->b1;

char k= 0; while(k= getch()){ switch(k){
case K_QUIT:	return 0;

case ']':clear(); draw_empty_level();
	//draw some sample rooms
	//for room size comparison
	//but maybe that's dependant on floor size
	getch(); clear(); make_level(clsn, b1);
	mvaddch(pos.y,pos.x, C_PLAYER);
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
	pos =player_move(k, pos, clsn); break;
default:	break;}}
return 0;}

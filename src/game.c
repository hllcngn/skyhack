#include "h.h"

void	game(GAME* gam){
vect	pos= gam->pos;
char*	clsn= gam->clsn;

make_level(clsn);
mvaddch(pos.y,pos.x, C_PLAYER);

char	k =0;
while (k =getch()){
switch(k){

case K_QUIT:	return;
case ']':clear(); draw_empty_level();
	//draw some sample rooms
	//for room size comparison
	//but maybe that's dependant on floor size
	getch(); clear(); make_level(clsn);
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

default:	break;}
}
return;}

#include "h.h"
#include <ncurses.h>
#include <stdlib.h>//malloc

void	game(){
vect	pos ={18,75};

char	**clsn =(char**)malloc(sizeof(char*)*LINES+1); clsn[LINES] =NULL;
for (int i =0; i<LINES; i++){
	clsn[i] =(char*)malloc(COLS+1); clsn[i][COLS] =0;
	for (int j=0; j<COLS; j++) clsn[i][j] =' ';}
//todo: free

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
	pos =player_move(k, pos, clsn); break;

default:	break;}
}
return;}

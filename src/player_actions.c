#include "h.h"
#include <ncurses.h>

vect	player_move(char k, vect pos, char **clsn){
vect	mv;
switch(k) {
case K_UP:		mv =(vect){-1, 0};	break;
case K_DOWN:		mv =(vect){ 1, 0};	break;
case K_LEFT:		mv =(vect){ 0,-1};	break;
case K_RIGHT:		mv =(vect){ 0, 1};	break;
case K_UP_LEFT:		mv =(vect){-1,-1};	break;
case K_UP_RIGHT:	mv =(vect){-1, 1};	break;
case K_DOWN_LEFT:	mv =(vect){ 1,-1};	break;
case K_DOWN_RIGHT:	mv =(vect){ 1, 1};	break;
default:				return pos;}
draw_floor_at(pos);
if (clsn[pos.y +mv.y][pos.x] !='X')
	pos.y +=mv.y;
if (clsn[pos.y][pos.x +mv.y] !='X')
	pos.x +=mv.x;
mvaddch(pos.y,pos.x, C_PLAYER);
return pos;}

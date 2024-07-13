#include "h.h"

void	player_move(char k, vect* pos, char *clsn){
vect	p =*pos, mv;
switch(k) {
case K_UP:		mv =(vect){-1, 0};	break;
case K_DOWN:		mv =(vect){ 1, 0};	break;
case K_LEFT:		mv =(vect){ 0,-1};	break;
case K_RIGHT:		mv =(vect){ 0, 1};	break;
case K_UP_LEFT:		mv =(vect){-1,-1};	break;
case K_UP_RIGHT:	mv =(vect){-1, 1};	break;
case K_DOWN_LEFT:	mv =(vect){ 1,-1};	break;
case K_DOWN_RIGHT:	mv =(vect){ 1, 1};	break;
default:					return;}
if (mv.y && clsn[p.x +(p.y +mv.y)*COLS] =='X')
	mv.y =0;
else	p.y +=mv.y;
if (mv.x && clsn[(p.x +mv.x) +p.y*COLS] =='X')
	mv.x =0;
else	p.x +=mv.x;
if (mv.y || mv.x){
	draw_floor_at(*pos);
	mvaddch(p.y,p.x, C_PLAYER);
	*pos =p;}}

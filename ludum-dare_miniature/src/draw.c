#include "INC.h"

void	draw_random_wall(LEVEL *lvl){
if (rn(2)){
	draw_rand_vert_wall(lvl);
	draw_rand_hor_wall(lvl);}
else {	draw_rand_hor_wall(lvl);
	draw_rand_vert_wall(lvl);}
return;}

void	draw_next_wall(LEVEL *lvl){
return;}

void	draw_rand_vert_wall(LEVEL *lvl){
//vect rangey rangex
//vect	ryx( 
int	y,x,z;
/*
ryx((rect){1,3, DG_iH,DG_iW-2}, &y,&x);
//y =rr(1,DG_iH); x =rr(3,DG_iW-2);
if	(y ==2)		y =1;
else if	(y ==DG_iH-1)	y =DG_iH;
do { z =rr(1,DG_iH);} while (abs(z-y)+1 <3);
if	(z ==2)		z =1;
else if	(z ==DG_iH-1)	z =DG_iH;
if (z >y)	vspacetil(lvl, y,x, S_DFLT_WALL, z-y+1, S_DFLT_WALL);
else		vspacetil(lvl, y,x, S_DFLT_WALL, z-y-1, S_DFLT_WALL); return;}
*/return;}
void	draw_rand_hor_wall(LEVEL *lvl){
/*
int	y,x,z;
y =rr(2,DG_iH-1); x =rr(1,DG_iW);
if	(x ==2)		x =1;
else if	(x ==DG_iW-1)	x =DG_iW;
do {z =rr(1,DG_iW);} while (abs(z-x)+1 <4);
if	(z ==2)		z =1;
else if	(z ==DG_iW-1)	z =DG_iW;
if (z >x)	spacetil(lvl, y,x, S_DFLT_WALL, z-x+1, S_DFLT_WALL);
else		spacetil(lvl, y,z, S_DFLT_WALL, z-x-1, S_DFLT_WALL); return;}
*/return;}

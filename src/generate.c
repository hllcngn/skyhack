#include "h.h"

//unused yet
void	make_level(char *clsn, buf1 b){
make_static_walls(clsn, b);
make_random_walls(b);}

	// v seems like I could improve this function
void	make_static_walls(char *clsn, buf1 b){
if(WALL_HL =='y')
attron(A_REVERSE);

/*
//top left corner room
vspace(1,15, C_WALL, 8); //rooms shouldn't be much smaller
space(8,1, C_WALL, 14);		//than 8x14
//random walls bottom left
space(35,23, C_WALL, 58); //corridor
vspace(19,23, C_WALL, LINES-1-19); //large left room
//room in the middle
box_space(13,79, C_WALL, 10,20);
//connecting middle room and bottom left
vspace(13+10,23+58+2, C_WALL, LINES-1-23);
*/

vspaceb1(b,1,15,C_WALL,8);
spaceb1(b,8,1,C_WALL,14);
spaceb1(b,35,23,C_WALL,58);
vspaceb1(b,19,23,C_WALL,LINES-1-19);
//box_space(13,79, C_WALL, 10,20);
vspaceb1(b,13+10,23+58+2,C_WALL,LINES-1-23);

if(WALL_HL =='y')
attroff(A_REVERSE);}


void	make_random_walls(buf1 b){
if(WALL_HL =='y')
attron(A_REVERSE);

int	minroomsize =4; //= cupboard
vect	size;
size.y =rrange(minroomsize, LINES/3);
size.x =rrange(minroomsize, COLS/4);
vect	coord;
coord.y =rn(LINES-1-size.y);
coord.x =rn(COLS-1-size.x); //random room
box_space(coord.y,coord.x, C_WALL, size.y,size.x);
//  todo: not overwrite the enclosing walls
box_space(0,COLS-15, C_WALL2, 6,15); //test room

boxb1(b, coord.y, coord.x, C_WALL, size.y, size.x);
boxb1(b, 0, COLS-15, C_WALL2, 6, 15);

if(WALL_HL =='y')
attroff(A_REVERSE);}

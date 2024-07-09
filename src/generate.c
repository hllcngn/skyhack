#include "h.h"

	// v seems like I could improve this function
void	make_static_walls(char *clsn){
if(WALL_HL =='y')
attron(A_REVERSE);

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

if(WALL_HL =='y')
attroff(A_REVERSE);}


void	make_random_walls(){
if(WALL_HL =='y')
attron(A_REVERSE);

int	minroomsize =4; //= cupboard
vect	randsize;
randsize.y =rrange(minroomsize, LINES/3);
randsize.x =rrange(minroomsize, COLS/4);
vect	randcoord;
randcoord.y =rn(LINES-1-randsize.y);
randcoord.x =rn(COLS-1-randsize.x); //random room
box_space(randcoord.y,randcoord.x, C_WALL, randsize.y,randsize.x);
//  todo: not overwrite the enclosing walls
box_space(0,COLS-15, C_WALL2, 6,15); //test room

if(WALL_HL =='y')
attroff(A_REVERSE);}

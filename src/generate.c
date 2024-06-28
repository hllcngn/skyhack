#include "h.h"
#include <ncurses.h>

void	make_WE_wall(int y,int x, int n, char *clsn){
//A_REVERSE check here?
 space( y,x, C_WALL, n);
 //space_buf( y,x, 'X', n, clsn);
return;}
void	make_NS_wall(int y,int x, int n, char *clsn){
 vspace(y,x, C_WALL, n);
// vspace_buf(clsn, y,x, 'X', n);
return;}

	// v seems like I could improve this function
void	generate_static_walls(char *clsn){
if(WALL_HL =='y')
attron(A_REVERSE);

make_NS_wall(1,15, 8, clsn);
make_WE_wall(8,1, 14, clsn);
//top left corner room
//vspace(1,15, ' ', 8); //rooms shouldn't be much smaller
//space(8,1, ' ', 14);		//than 8x14
//random walls bottom left
space(35,23, ' ', 58); //corridor
vspace(19,23, ' ', LINES-1-19); //large left room
//room in the middle
box_space(13,79, ' ', 10,20);
//connecting middle room and bottom left
vspace(13+10,23+58+2, ' ', LINES-1-23);

if(WALL_HL =='y')
attroff(A_REVERSE);
return;}

void	generate_random_walls(){
attron(A_REVERSE);

int	minroomsize =4; //= cupboard
vect	randsize;
randsize.y =rrange(minroomsize, LINES/3);
randsize.x =rrange(minroomsize, COLS/4);
vect	randcoord;
randcoord.y =rn(LINES-1-randsize.y);
randcoord.x =rn(COLS-1-randsize.x); //random room
box_space(randcoord.y,randcoord.x, '.', randsize.y,randsize.x);
//  todo: not overwrite the enclosing walls
box_space(0,COLS-15, '+', 6,15); //test room

attroff(A_REVERSE);
return;}

#include "h.h"

void	make_level(char *clsn, buf1 b){
make_static_walls(clsn, b);
make_random_walls(clsn, b);}

	// v seems like I could improve this function
void	make_static_walls(char *clsn, buf1 b){
if(WALL_HL =='y')
attron(A_REVERSE);

/*
vspace(1,15, C_WALL, 8); //rooms shouldn't be much smaller
space(8,1, C_WALL, 14);		//than 8x14
space(35,23, C_WALL, 58); //corridor
vspace(19,23, C_WALL, LINES-1-19); //large left room
box_space(13,79, C_WALL, 10,20);
vspace(13+10,23+58+2, C_WALL, LINES-1-23);
*/

//top left corner room
vspaceb1(b,1,15,C_WALL,8);
spaceb1(b,8,1,C_WALL,14);
//random walls bottom left
spaceb1(b,35,23,C_WALL,58);
vspaceb1(b,19,23,C_WALL,LINES-1-19);
//room in the middle
//box_space(13,79, C_WALL, 10,20);
//connecting middle room and bottom left
vspaceb1(b,13+10,23+58+2,C_WALL,LINES-1-23);

if(WALL_HL =='y')
attroff(A_REVERSE);}


void	make_random_walls(char* clsn, buf1 b){
if(WALL_HL =='y')
attron(A_REVERSE);

int	minroomsize =4; //= cupboard
vect	size;
size.y =rrange(minroomsize, LINES/3);
size.x =rrange(minroomsize, COLS/4);
vect	coord;
coord.y =rn(LINES-1-size.y);
coord.x =rn(COLS-1-size.x); //random room
box_space(coord.y,coord.x, C_WALL, size.y,size.x); //< prints
//  todo: not overwrite the enclosing walls
box_space(0,COLS-15, C_WALL2, 6,15); //test room

boxb0(clsn, b.w, coord.y, coord.x, 'X', size.y, size.x);
boxb0(clsn, b.w, 0, COLS-15, 'X', 6, 15);

boxb1(b, coord.y, coord.x, C_WALL, size.y, size.x);
boxb1(b, 0, COLS-15, C_WALL2, 6, 15);

if(WALL_HL =='y')
attroff(A_REVERSE);}


void	generate_path(vect* p, int n){
p[0] = (vect){LINES-2, COLS/2};
int x = randn()%2;
p[1] = (x ==0? (vect){rn(LINES-1), p[0].x} : (vect){p[0].y, rn(COLS-1)});
for (int i =2; i <n; i++){
	if (p[i-1].x != p[i-2].x)
		p[i] = (vect){rn(LINES-1), p[i-1].x};
	else
		p[i] = (vect){p[i-1].y, rn(COLS-1)};
}}

void	build_from_path(char* clsn, int w, vect* p, int n){
if (p[0].x == p[1].x){
	int y =rrange(p[1].y, p[0].y);
	clsn[y*w + p[0].x] = 'D';
}
}

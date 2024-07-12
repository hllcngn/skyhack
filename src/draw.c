#include "h.h"

void	draw_level(char* clsn, buf1 b){
draw_entire_floor();
make_static_walls(clsn);
make_random_walls();
draw_enclosing_walls();}

void	draw_empty_level(){
draw_entire_floor();
draw_enclosing_walls();}

void	draw_entire_floor(){
attron(A_DIM);
if	(FLOOR_TYPE=='s')
fill_term(C_FLOOR);
else if	(FLOOR_TYPE=='p'){
if	(PAVING=='|')
for (int i=0; i<LINES; i++) //| on even x /_ on odd
	space1in2(i,0, '|','_', COLS);
else if	(PAVING=='+')
for (int i=0; i<LINES; i++) //+ on even x
	space1in2(i,0, '+',' ', COLS);
else if (PAVING=='/')
for (int i=0; i<LINES; i+=2){ //even y: / on even x/\ on odd
	space1in2(i,0, '/','\\', COLS);
	space1in2(i+1,0, '\\','/', COLS);}}
attroff(A_DIM);}

void	draw_enclosing_walls(){
if	(OUTWALL_HL =='y')
attron(A_REVERSE);
space(0,0, '-', COLS);
space(LINES-1,0, '-', COLS);
vspace(0,0, '|', LINES);
vspace(0,COLS-1, '|', LINES);
if	(OUTWALL_HL =='y')
attroff(A_REVERSE);}

void	draw_floor_at(vect pos){
move(pos.y,pos.x);
if	(FLOOR_TYPE=='s')
addch('.');
else if	(FLOOR_TYPE=='p'){
if	(PAVING=='|')
if (pos.x%2)	addch('_');
else		addch('|');
else if	(PAVING=='+')
if (pos.x%2)	addch(' ');
else		addch('+');
else if	(PAVING=='/')
if (pos.x%2)	if (pos.y%2)	addch('/');
		else		addch('\\');
else		if (pos.y%2)	addch('\\');
		else		addch('/');}}


void	draw_path(vect* pts, int n){
for (int i =0; i <n-1; i++){
if (pts[i].y == pts[i+1].y){
	int nn = pts[i+1].x -pts[i].x;
	if (!nn)	continue;
	nn>0 ? nn++ : nn--;	//including both points
	space(pts[i], C_PATH, nn);}
else if (pts[i].x == pts[i+1].x){
	int nn = pts[i+1].y -pts[i].y;
	if (!nn)	continue;
	nn>0 ? nn++ : nn--;
	vspace(pts[i], C_PATH, nn);}
else	break;}}

void	draw_path2(vect* pts, int n){
for (int i =0; i <n-1; i++){
int dy = pts[i+1].y -pts[i].y;
int dx = pts[i+1].x -pts[i].x;
if (!dy){ if (!dx)	continue;
	dx >0 ?	space(pts[i], C_PATH, dx+1) :
		space(pts[i+1], C_PATH, -dx+1);}
else if (!dx){ if (!dy)	continue;
	dy >0 ?	vspace(pts[i], C_PATH, dy+1) :
		vspace(pts[i+1], C_PATH, -dy+1);}
else	break;}}

#include "h.h"

void	draw_buf(buf1 b){
for (int y =0; y <b.h; y++)
for (int x =0; x <b.w; x++)
	if (b.c[x +y*b.w])
		mvaddch(y, x, b.c[x +y*b.w]);}

void	draw_level(char* clsn, buf1 b){
draw_entire_floor();
make_static_walls(clsn, b);
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

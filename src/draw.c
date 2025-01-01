#include "h.h"


void	draw_level(char* clsn, buf1 b){
draw_entire_floor();
draw_buf(b);
draw_clsn(clsn, b.w, b.h);
//make_static_walls(clsn, b);
make_random_walls(clsn, b);
draw_enclosing_walls(clsn, b.w);}


void	draw_buf(buf1 b){
for (int y =0; y <b.h; y++) for (int x =0; x <b.w; x++)
	if (b.c[x +y*b.w])	mvaddch(y, x, b.c[x +y*b.w]);}


void	draw_empty_level(char* clsn, int w){
draw_entire_floor();
draw_enclosing_walls(clsn, w);}


void	draw_entire_floor(){
attron(A_DIM);
if	(FLOOR_TYPE=='s')	fill_term(C_FLOOR);
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


void	draw_enclosing_walls(char* clsn, int w){
if	(OUTWALL_HL =='y')	attron(A_REVERSE);
space(0,0, '-', COLS);
space(LINES-1,0, '-', COLS);
vspace(0,0, '|', LINES);
vspace(0,COLS-1, '|', LINES);
if	(OUTWALL_HL =='y')	attroff(A_REVERSE);

//there could be other ways to handle such collision
spaceb0(clsn, w, 0, 0, 'X', COLS);
spaceb0(clsn, w, LINES-1, 0, 'X', COLS);
vspaceb0(clsn, w, 0, 0, 'X', LINES);
vspaceb0(clsn, w, 0, COLS-1, 'X', LINES);}


void	draw_clsn(char* clsn, int w, int h){
for (int i =0; i <w*h; i++)
	if (clsn[i] == 'D')	mvaddch(i/w, i%w, 'D');}


void	draw_floor_at(vect pos){
move(pos.y,pos.x);
if	(FLOOR_TYPE=='s')	addch('.');
else if	(FLOOR_TYPE=='p'){
	if	(PAVING=='|'){
		if (pos.x%2)	addch('_');
		else		addch('|');}
	else if	(PAVING=='+'){
		if (pos.x%2)	addch(' ');
		else		addch('+');}
	else if	(PAVING=='/')
		if (pos.x%2){	if (pos.y%2)	addch('/');
				else		addch('\\');}
		else{		if (pos.y%2)	addch('\\');
				else		addch('/');}}}

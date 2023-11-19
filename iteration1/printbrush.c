#include "h.h"
#include <ncurses.h>

void space_yx(int y,int x, char c, int n){//todo:swap c and n args
 move(y,x); for (int i=0; i<n; i++) addch(c); return;}
void space_vect(vect coord, char c, int n){
 move(coord.y,coord.x); for (int i=0; i<n; i++) addch(c); return;}

void	space_buf_yx(int y,int x, char c, int n, char **cbuf){
char	*l =cbuf[y];  //y mustn't exceed buf size
for (int i =0; l[x+i] && i<n; i++)  //x neither
	l[x+i] =c;}  //hwvr won't overflow if n too large
//the other solution is to have a buf struct containing size info

void space1in2(int y,int x, char c1,char c2, int n){
 move(y,x); int i =0; for (; i<n; i+=2){addch(c1); addch(c2);}
 if (i =n) addch(c1); return;}

void vspace_yx(int y,int x, char c, int n){
 for (int i =0; i<n; i++){move(y+i,x); addch(c);} return;}
void vspace_vect(vect coord, char c, int n){
 for (int i =0; i<n; i++){move(coord.y+i,coord.x); addch(c);} return;}

void fill_term(char c){
 move(0,0); for (int i =0; i<LINES*COLS; i++) addch(c); return;}
void fill_space(int y,int x, char c, int h,int w){
 for (int i=0; i<h; i++) space(y+i,x, c, w); return;}

void	box_space(int y,int x, char c, int h,int w){
space(y,x, c, w);
space(y+h-1,x, c, w);  //non inclusive of the upper limit
vspace(y,x, c, h);  // ex 13+10=23 but drawing 13-22 (10 total)
vspace(y,x+w-1, c, h);
return;}

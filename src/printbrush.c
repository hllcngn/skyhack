#include <ncurses.h>
#include "struct.h"
#include "prototypes.h"

void stroke(vect p1, vect p2, char c){
int dy = p2.y -p1.y;
int dx = p2.x -p1.x;
if (!dy && dx){
	dx >0 ?	move(p1.y, p1.x):
		move(p2.y, p2.x);
	for (int n =abs(dx); n >=0; n--) addch(c);}
else if (dy && !dx){
	int or= (dy >0 ? p1.y : p2.y);
	for (int n =abs(dy); n >=0; n--)
		mvaddch(or+n, p1.x, c);}}
void bstroke(buf1 b, vect p1, vect p2, char c){
int dy = p2.y -p1.y;
int dx = p2.x -p1.x;
if (!dy && dx){
	int or= (dx >0 ? p1.x : p2.x);
	for (int n =abs(dx); n >=0; n--)
		b.c[or+n +p1.y*b.w]=c;}
else if (dy && !dx){
	int or= (dy >0 ? p1.y : p2.y);
	for (int n =abs(dy); n >=0; n--)
		b.c[p1.x +(or+n)*b.w]=c;}}


void space_yx(int y,int x, char c, int n){//todo:swap c and n args
 move(y,x); for (int i=0; i<n; i++) addch(c);}
void space_vect(vect coord, char c, int n){
 if (n>0)	move(coord.y,coord.x);
 else		move(coord.y,coord.x+n+1);
 for (int i=0; i<abs(n); i++) addch(c);}

void	space_buf_yx(int y,int x, char c, int n, char **cbuf){
char	*l =cbuf[y];  //y mustn't exceed buf size
for (int i =0; l[x+i] && i<n; i++)  //x neither
	l[x+i] =c;}  //hwvr won't overflow if n too large
//the other solution is to have a buf struct containing size info
void	spaceb1(buf1 b, int y, int x, char c, int n){
for (int dx =0; dx <n; dx++)
	b.c[x+dx +y*b.w] = c;}
void	spaceb0(char* b, int w, int y, int x, char c, int n){
for (int dx =0; dx <n; dx++)
	b[x+dx +y*w] = c;}

void space1in2(int y,int x, char c1,char c2, int n){
 move(y,x); int i =0; for (; i<n; i+=2){addch(c1); addch(c2);}
 if (i =n) addch(c1);}


void vspace_yx(int y,int x, char c, int n){
 for (int i =0; i<n; i++){move(y+i,x); addch(c);}}
void vspace_vect(vect coord, char c, int n){
 if (n>0) for (int i =0; i<n; i++){move(coord.y+i,coord.x); addch(c);}
 else for (int i =0; i>n; i--){move(coord.y+i,coord.x); addch(c);}}
void	vspaceb1(buf1 b, int y, int x, char c, int n){
for (int dy =0; dy <n; dy++)
	b.c[x +(y+dy)*b.w] = c;}
void	vspaceb0(char* b, int w, int y, int x, char c, int n){
for (int dy =0; dy <n; dy++)
	b[x +(y+dy)*w] = c;}


void	box_space(int y,int x, char c, int h,int w){
space(y,x, c, w);
space(y+h-1,x, c, w);  //non inclusive of the upper limit
vspace(y,x, c, h);  // ex 13+10=23 but drawing 13-22 (10 total)
vspace(y,x+w-1, c, h);}


void	path(vect* pts, int n){
for (int i =0; i <n-1; i++)
	stroke(pts[i],pts[i+1],C_PATH);}


void fill_term(char c){
 move(0,0); for (int i =0; i<LINES*COLS; i++) addch(c);}
void fill_space(int y,int x, char c, int h,int w){
 for (int i=0; i<h; i++) space(y+i,x, c, w);}

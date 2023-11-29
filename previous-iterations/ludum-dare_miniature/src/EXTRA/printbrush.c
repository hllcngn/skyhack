#include <ncurses.h>
#include "printbrush.h"

void pr_stroke_yx(int y,int x, char c, int n){//todo:swap c and n args
 move(y,x); for (int i=0; i<n; i++) addch(c); return;}
void pr_stroke_vect(vect coord, char c, int n){
 move(coord.y,coord.x); for (int i=0; i<n; i++) addch(c); return;}

void pr_stroke1in2(int y,int x, char c1,char c2, int n){
 move(y,x); int i =0; for (; i<n; i+=2){addch(c1); addch(c2);}
 if (i =n) addch(c1); return;}

void pr_vstroke_yx(int y,int x, char c, int n){
 for (int i =0; i<n; i++){move(y+i,x); addch(c);} return;}
void pr_vstroke_vect(vect coord, char c, int n){
 for (int i =0; i<n; i++){move(coord.y+i,coord.x); addch(c);} return;}

void pr_fill_term(char c){
 move(0,0); for (int i =0; i<LINES*COLS; i++) addch(c); return;}
void pr_fill(int y,int x, char c, int h,int w){
 for (int i=0; i<h; i++) pr_stroke(y+i,x, c, w); return;}

void	pr_box(int y,int x, char c, int h,int w){
pr_stroke(y,x, c, w);
pr_stroke(y +h-1,x, c, w);  //non inclusive of the upper limit
pr_vstroke(y,x, c, h);  // ex 13+10=23 but drawing 13-22 (10 total)
pr_vstroke(y,x +w-1, c, h);
return;}

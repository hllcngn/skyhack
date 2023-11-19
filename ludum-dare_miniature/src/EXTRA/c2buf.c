#include "c2buf.h"
#include <stdlib.h>//malloc,free
#include <stdio.h>//c2_print
#include <ncurses.h>//c2_disp

c2buf	*alloc_c2buf(int h,int w){
c2buf	*new =(c2buf*)malloc(sizeof(c2buf));

new->h =h; new->w =w;
int htot =h+2, wtot =w+1;
new->htot =htot; new->wtot =wtot;
int sizetot =htot*wtot;
new->sizetot =sizetot;

char *b =(char*)malloc(sizetot);
new->b =b;
char *c =b +wtot;
new->c =c;
char **k =(char**)malloc(htot);
new->k =k;
char **l =k +sizeof(char*);
new->l =l;

for (int i=0; i<sizetot; i++)
	b[i] =' ';

for (int i=0; i<wtot; i++){
	b[i] =0;
	b[sizetot-wtot+i] =0;}

k[0] =NULL;
k[htot-1] =NULL;
for (int i=0; i<h; i++){
	l[i] =c +i*wtot;
	l[i][w] =0;}
return new;}


void	free_c2buf(c2buf* b){
free(b->k);
free(b->b);
free(b); return;}


void	c2_print(c2buf *b){
//for (char **p =b->l; *p; p+=sizeof(char*))
//	printf("%s\n", *p);
for (int i=0; i<b->h; i++)
	printf("%s\n", b->l[i]);
return;}

void	c2_disp(c2buf *b, int y,int x){
/*
for (int i=0; i<b->h; i++)
//	mvprintw(y+i,x,"%s", b->l[i]);
	mvaddnstr(y+i,x, b->l[i], b->w);
*/
for (int i =0; i<5; i++){
	move(y+i,x);
	for (int j =0; j<5; j++)
		//addch(b->l[i][j]);// <-- segv if called after a getch
		addch('+');
}
return;}

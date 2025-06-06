#include "h.h"

vect	get_move_vector(char c){
vect v = (vect){0,0};
switch (c){
case 'w': v = (vect){-1,0}; break;
case 'a': v = (vect){0,-1}; break;
case 's': v = (vect){1,0}; break;
case 'd': v = (vect){0,1}; break;
case 'q': v = (vect){-1,-1}; break;
case 'e': v = (vect){-1,1}; break;
case 'z': v = (vect){1,-1}; break;
case 'x': v = (vect){1,1}; break;}
return v;}

void	time_add_s(TIME *t, int s){
int xtra_m = 0;
int xtra_h = 0;
int xtra_d = 0;
t->s += s;
if (t->s >= 60){
	xtra_m = t->s/60;
	t->s %= 60;}
t->m += xtra_m;
if (t->m >= 60){
	xtra_h = t->m/60;
	t->m %= 60;}
t->h += xtra_h;
if (t->h >= 24){
	xtra_d = t->h/24;
	t->h %=24;}
t->d += xtra_d;}

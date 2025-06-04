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

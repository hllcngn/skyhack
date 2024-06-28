#include "h.h"

int main2(GAME* gam){

gam->pos= (vect){18,75};
char* clsn= malloc(LINES*COLS);
for(int i= 0;i< LINES*COLS;i++)
	clsn[i]= ' ';
gam->clsn= clsn;
//todo: free

game(gam);
return 0;}

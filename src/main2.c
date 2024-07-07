#include "h.h"

int main2(GAME* gm){

gm->pos= (vect){18,75};
char* clsn= malloc(LINES*COLS);
for(int i= 0;i< LINES*COLS;i++)
	clsn[i]= ' ';
gm->clsn= clsn;

game(gm);

free(gm->clsn);
return 0;}

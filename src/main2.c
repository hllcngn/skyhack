#include "h.h"

int main2(GAME* gm){
vect pos = (vect){18,75};
char* clsn = malloc(LINES*COLS);
for(int i= 0;i < LINES*COLS; i++) clsn[i]= ' ';
buf1 b;
b.h = LINES; b.w = COLS;
b.c = malloc(b.h*b.w);
make_level(clsn, b);
mvaddch(pos.y,pos.x, C_PLAYER);

gm->pos = pos;
gm->clsn = clsn;
gm->b1 = b;
game(gm);

free(gm->clsn);
free(gm->b1.c);
return 0;}

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

vect* pts = malloc(sizeof(vect)*5);
pts[0] = (vect){30,5};
pts[1] = (vect){20,5};
pts[2] = (vect){20,18};
pts[3] = (vect){30,18};
pts[4] = (vect){30,15};
draw_path(pts,5);

gm->pos = pos;
gm->clsn = clsn;
gm->b1 = b;
game(gm);

free(gm->clsn);
free(gm->b1.c);
return 0;}

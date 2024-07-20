#include "h.h"

int main2(GAME* gm, int new_player){
char* clsn = malloc(LINES*COLS);
 for(int i= 0;i < LINES*COLS; i++) clsn[i]= ' ';

buf1 b;
if (!new_player){
	b.h = LINES; b.w = COLS;
	b.c = calloc(b.h*b.w,1);
	make_level(clsn, b);}
else{
	FILE* f =fopen("saves/save1","r");
	rng_init(f);
	b.h = 0; b.w = 0;
	load_buf(f, &b);
	//draw_empty_level();
	draw_level(clsn, b.w, b);
	draw_buf(b);
	fclose(f);}

vect pos = (vect){18,75};

mvaddch(pos.y,pos.x, C_PLAYER);


vect* pts = malloc(sizeof(vect)*5);
pts[0] = (vect){30,5};
pts[1] = (vect){20,5};
pts[2] = (vect){20,18};
pts[3] = (vect){30,18};
pts[4] = (vect){30,15};
path(pts,5);


gm->pos = pos;
gm->clsn = clsn;
gm->b1 = b;
game(gm);

save_buf("saves/save1",gm->b1);

free(gm->clsn);
free(gm->b1.c);
return 0;}

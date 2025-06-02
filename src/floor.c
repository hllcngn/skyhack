#include "h.h"
#include "myncurses.h"

FLOOR	*floor_new(int floorn, int h, int w){
FLOOR *floor = malloc(sizeof(FLOOR));
floor->floorn = floorn;
floor->h = h;
floor->w = w;
floor->buf = malloc(sizeof(char*) * floor->h);
for (int i = 0; i < floor->h; i++)
	floor->buf[i] = malloc(floor->w);
for (int i = 0; i < floor->w; i++){
	floor->buf[0][i] = 'H';
	floor->buf[floor->h-1][i] = 'H';}
for (int i = 1; i < floor->h-1; i++){
	floor->buf[i][0] = 'H';
	floor->buf[i][floor->w-1] = 'H';
	for (int j = 1; j < floor->w-1; j++)
		floor->buf[i][j] = '.';}
return floor;
}

void	floor_free(FLOOR *floor){
for (int i = 0; i < floor->h; i++)
	free(floor->buf[i]);
free(floor->buf);
free(floor);
}

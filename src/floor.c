#include "h.h"

FLOOR	*floor_new(int floorn, int h, int w){
FLOOR *new = malloc(sizeof(FLOOR));
new->floorn = floorn;
new->h = h;
new->w = w;

// floor & outside walls
new->buf = malloc(sizeof(char*) * new->h);
for (int i = 0; i < new->h; i++)
	new->buf[i] = malloc(new->w);
for (int i = 0; i < new->w; i++){
	new->buf[0][i] = 'H';
	new->buf[new->h-1][i] = 'H';}
for (int i = 1; i < new->h-1; i++){
	new->buf[i][0] = 'H';
	new->buf[i][new->w-1] = 'H';
	for (int j = 1; j < new->w-1; j++)
		new->buf[i][j] = '.';}

new->characters = NULL;
return new;}

void	floor_free(FLOOR *floor){
for (int i = 0; i < floor->h; i++)
	free(floor->buf[i]);
free(floor->buf);
list_free(floor->characters);
free(floor);}

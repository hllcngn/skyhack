#include "h.h"

DUNGEON	*dungeon_new(int h, int w){
DUNGEON *new = malloc(sizeof(DUNGEON));
new->h = h; new->w = w;
new->nfloor = (new->h + new->w)/2.0 /2 *8 /4.5;
new->floor = malloc(sizeof(FLOOR*) * new->nfloor);
for (int i = 0; i < new->nfloor; i++)
	new->floor[i] = floor_new(i, new->h, new->w);
dungeon_add_stairs(new);
return new;}

void	dungeon_free(DUNGEON *dungeon){
for (int i = 0; i < dungeon->nfloor; i++)
	floor_free(dungeon->floor[i]);
free(dungeon->floor);
free(dungeon);}

void	dungeon_add_stairs(DUNGEON *dungeon){
for (int i = 0; i < dungeon->nfloor-1; i++){
	int stairsy = rand()%(dungeon->h-2)+1;
	int stairsx = rand()%(dungeon->w-2)+1;
	dungeon->floor[i]->buf[stairsy][stairsx] = '>';
	dungeon->floor[i+1]->buf[stairsy][stairsx] = '<';}}

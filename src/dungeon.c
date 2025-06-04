#include "h.h"

DUNGEON	*dungeon_new(int h, int w){
DUNGEON *new = malloc(sizeof(DUNGEON));
new->h = h; new->w = w;
new->nfloor = (new->h + new->w)/2.0 /2 *8 /4.5;
new->floor = malloc(sizeof(FLOOR*) * new->nfloor);
for (int i = 0; i < new->nfloor; i++)
	new->floor[i] = floor_new(i, new->h, new->w);
return new;}

void	dungeon_free(DUNGEON *dungeon){
for (int i = 0; i < dungeon->nfloor; i++)
	floor_free(dungeon->floor[i]);
free(dungeon->floor);
free(dungeon);}

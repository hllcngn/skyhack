#include "h.h"
#include "myncurses.h"

DUNGEON	*dungeon_new(void){
DUNGEON *dungeon = malloc(sizeof(DUNGEON));
dungeon->h = LINES-2; dungeon->w = COLS;
dungeon->nfloor = (dungeon->h + dungeon->w)/2.0 /2 *8 /4.5;
dungeon->floor = malloc(sizeof(FLOOR*) * dungeon->nfloor);
for (int i = 0; i < dungeon->nfloor; i++)
	dungeon->floor[i] = floor_new(i, dungeon->h, dungeon->w);
return dungeon;
}

void	dungeon_free(DUNGEON *dungeon){
for (int i = 0; i < dungeon->nfloor; i++)
	floor_free(dungeon->floor[i]);
free(dungeon->floor);
free(dungeon);
}

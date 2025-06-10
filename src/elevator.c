#include "h.h"

ELEVATOR	*elevator_new(int y, int x, int floorn){
ELEVATOR *new = malloc(sizeof(ELEVATOR));
new->door_open = 0;
new->floor = malloc(sizeof(FLOOR));
new->floor->floorn = floorn;
new->floor->h = 4;
new->floor->w = 5;
new->floor->y = y;
new->floor->x = x;
new->floor->buf = malloc(sizeof(char*)*new->floor->h);
for (int i = 0; i < new->floor->h; i++)
	new->floor->buf[i] = malloc(new->floor->w);
strncpy(new->floor->buf[0], "_____", 5);
strncpy(new->floor->buf[1], "|...|", 5);
strncpy(new->floor->buf[2], "|...|", 5);
strncpy(new->floor->buf[3], "|[I]|", 5);
new->floor->characters = NULL;
return new;}

void	elevator_call(DUNGEON* dungeon){
dungeon->elevator->floor->floorn = dungeon->currfloor->floorn;
dungeon->elevator->door_open = 1;
strncpy(dungeon->floor[dungeon->currfloor->floorn]->buf[dungeon->elevator->floor->y+3]
		+dungeon->elevator->floor->x+1, "].[", 3);
strncpy(dungeon->elevator->floor->buf[3]+1, "].[", 3);}

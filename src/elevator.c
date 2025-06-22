#include "h.h"

ELEVATOR	*elevator_new(int floorn, int y, int x){
ELEVATOR *new = malloc(sizeof(ELEVATOR));
new->door_open = 0;
new->floor = floor_new(floorn, 4, 5, y, x);
strncpy(new->floor->buf[0], "_____", 5);
strncpy(new->floor->buf[1], "|...|", 5);
strncpy(new->floor->buf[2], "|...|", 5);
strncpy(new->floor->buf[3], "|[I]|", 5);
return new;}

void	elevator_free(ELEVATOR *elev){
floor_free(elev->floor);
free(elev);}

void	elevator_call(DUNGEON* dungeon){
strncpy(dungeon->floor[dungeon->elevator->floor->floorn]->buf[dungeon->elevator->floor->y+3]
		+dungeon->elevator->floor->x+1, "[I]", 3);
dungeon->elevator->floor->floorn = dungeon->currfloor->floorn;
dungeon->elevator->door_open = 1;
strncpy(dungeon->floor[dungeon->currfloor->floorn]->buf[dungeon->elevator->floor->y+3]
		+dungeon->elevator->floor->x+1, "].[", 3);
strncpy(dungeon->elevator->floor->buf[3]+1, "].[", 3);}

#include "h.h"

DUNGEON	*dungeon_new(int h, int w){
DUNGEON *new = malloc(sizeof(DUNGEON));
new->h = h; new->w = w;
new->nfloor = (new->h + new->w)/2.0 /2 *8 /4.5;
new->floor = malloc(sizeof(FLOOR*) * new->nfloor);
for (int i = 0; i < new->nfloor; i++)
	new->floor[i] = floor_new_dungeon_floor(i, new->h, new->w);
dungeon_add_stairs(new);
dungeon_add_elevators(new);
new->currfloor = new->floor[0];
return new;}

void	dungeon_free(DUNGEON *dungeon){
for (int i = 0; i < dungeon->nfloor; i++)
	floor_free(dungeon->floor[i]);
free(dungeon->floor);
elevator_free(dungeon->elevator);
free(dungeon);}


void	dungeon_add_stairs(DUNGEON *dungeon){
for (int i = 0; i < dungeon->nfloor-1; i++){
	int stairsy = rand()%(dungeon->h-2)+1;
	int stairsx = rand()%(dungeon->w-2)+1;
	dungeon->floor[i]->buf[stairsy][stairsx] = '>';
	dungeon->floor[i+1]->buf[stairsy][stairsx] = '<';}}

void	dungeon_add_elevators(DUNGEON *dungeon){// TODO check for collision with stairs
int elevy = rand()%(dungeon->h-2-4)+1;
int elevx = rand()%(dungeon->w-2-4)+1;
int elevfloorn = rand()%dungeon->nfloor;
dungeon->elevator = elevator_new(elevfloorn, elevy, elevx);
for (int i = 0; i < dungeon->nfloor-1; i++){
	strncpy(dungeon->floor[i]->buf[elevy]+elevx,   "_____", 5);
	strncpy(dungeon->floor[i]->buf[elevy+1]+elevx, "|   |", 5);
	strncpy(dungeon->floor[i]->buf[elevy+2]+elevx, "|   |", 5);
	strncpy(dungeon->floor[i]->buf[elevy+3]+elevx, "|[I]|", 5);}}

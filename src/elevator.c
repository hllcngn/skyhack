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

void	elevator_handle_doorway(char k, char hit, DUNGEON *dungeon, CHARACTER *player){
if (player->currfloor == dungeon->floor[dungeon->currfloor->floorn]
		&& (player->y == dungeon->elevator->floor->y+3
			&& player->x == dungeon->elevator->floor->x+2)
		&& (k == 'w' || k == 'q' || k == 'e')){
	player_change_floor(dungeon, dungeon->elevator->floor, player);}
else if (player->currfloor == dungeon->elevator->floor
		&&(player->y == 3 && player->x == 2)
		&&(k == 's' || k == 'z' || k == 'x')
		&&hit == 1){
	player_change_floor(dungeon, dungeon->floor[dungeon->currfloor->floorn], player);
	vect v = get_move_vector(k);
	character_movement(player->currfloor, player, v);}}

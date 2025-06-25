#include "h.h"

void	player_movement(List **stack, TIME *time, void *player, DUNGEON *dungeon, void *k){
vect v = get_move_vector(*(char*)k);
int hit = character_movement(dungeon->currfloor, player, v);
handle_hit(stack, dungeon, player, hit, *(char*)k);
elevator_handle_doorway(*(char*)k, hit, dungeon, player);
time_add_s(time, 1);}

void	player_change_floor(DUNGEON *dungeon, FLOOR *floor_new,
		CHARACTER *player){
character_change_floor(floor_new, player);
dungeon->currfloor = floor_new;}

void	player_change_floor_stairs(DUNGEON *dungeon, CHARACTER* player,
		TIME *time, char stairs){
switch(stairs){
case '>':
player_change_floor(dungeon, dungeon->floor[dungeon->currfloor->floorn+1], player);
	break;
case '<':
player_change_floor(dungeon, dungeon->floor[dungeon->currfloor->floorn-1], player);
	break;}
time_add_s(time, 30);}

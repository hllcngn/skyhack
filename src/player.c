#include "h.h"

void	player_change_floor(DUNGEON *dungeon, FLOOR *floor_new, CHARACTER *player){
character_change_floor(floor_new, player);
dungeon->currfloor = floor_new;}

void	player_change_floor_stairs(DUNGEON *dungeon, CHARACTER* player, TIME *time, char stairs){
switch(stairs){
case '>': player_change_floor(dungeon, dungeon->floor[dungeon->currfloor->floorn+1], player); break;
case '<': player_change_floor(dungeon, dungeon->floor[dungeon->currfloor->floorn-1], player); break;}
time_add_s(time, 30);}

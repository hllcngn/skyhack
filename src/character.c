#include "h.h"

CHARACTER	*character_new(int y, int x, int floorn, FLOOR* floor, char c){
CHARACTER *new = malloc(sizeof(CHARACTER));
new->y = y; new->x = x; new->floorn = floorn;
new->currfloor = floor;
new->c = c;
return new;}

void	character_free(CHARACTER *character){
free(character);}


char	character_movement(FLOOR *floor, CHARACTER *character, vect v){
int collision = check_collision(floor, character->y+v.y, character->x+v.x);
if (!collision){
	character->y += v.y;
	character->x += v.x;
	return 0;}
return collision;}

void	character_change_floor(FLOOR *old_floor, FLOOR *new_floor, CHARACTER *character){
List *pl = list_pop(&old_floor->characters, character);
list_push_front(&new_floor->characters, pl);
if (new_floor->y){
	character->y = character->y - new_floor->y;
	character->x = character->x - new_floor->x;}
else if (old_floor->y){
	character->y = character->y + old_floor->y;
	character->x = character->x + old_floor->x;}
character->floorn = new_floor->floorn;
character->currfloor = new_floor;}

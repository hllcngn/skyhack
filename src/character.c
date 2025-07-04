#include "h.h"

CHARACTER	*character_new(int y, int x, FLOOR* floor, char c){
CHARACTER *new = malloc(sizeof(CHARACTER));
new->y = y; new->x = x;
new->currfloor = floor;
new->c = c;
return new;}

void	character_free(CHARACTER *character){
free(character);}


char	character_movement(FLOOR *floor, CHARACTER *character, vect v){
int collision = check_collision(floor, character->y+v.y, character->x+v.x);
if (!collision){	character->y += v.y;
			character->x += v.x;
			return 0;} return collision;}

// doesn't this get used only to increment or decrement the floorn
// or move to and from the elevator?
void	character_change_floor(FLOOR *new_floor, CHARACTER *character){
List *pl = list_pop(&character->currfloor->characters, character);
list_push_front(&new_floor->characters, pl);
if (new_floor->y){
	character->y -= new_floor->y;
	character->x -= new_floor->x;}
else if (character->currfloor->y){
	character->y += character->currfloor->y;
	character->x += character->currfloor->x;}
character->currfloor = new_floor;}

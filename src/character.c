#include "h.h"

CHARACTER	*character_new(int y, int x, char c){
CHARACTER *new = malloc(sizeof(CHARACTER));
new->y = y; new->x = x;
new->c = c;
return new;}

void	character_free(CHARACTER *character){
free(character);}

void	character_movement(FLOOR *floor, CHARACTER *character, vect v){
int collision = check_collision(floor, character->y+v.y, character->x+v.x);
if (!collision){
	character->y += v.y;
	character->x += v.x;}}


#include "h.h"

CHARACTER	*character_new(int y, int x, char c){
CHARACTER *new = malloc(sizeof(CHARACTER));
new->y = y; new->x = x;
new->c = c;
return new;}

void	character_free(CHARACTER *character){
free(character);}

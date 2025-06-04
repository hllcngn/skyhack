#include "h.h"

int	check_collision(FLOOR *floor, int y, int x){
int collision = 0;
char c = floor->buf[y][x];
switch (c){
case 'H': collision = 1; break;}
return collision;}

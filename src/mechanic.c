#include "h.h"

int	check_collision(FLOOR *floor, int y, int x){
if (y >= floor->h || x >= floor->w) return 1;
int collision = 0;
char c = floor->buf[y][x];
switch (c){
// walls
case 'H': collision = 1; break;
case '_': collision = 1; break;
case '|': collision = 1; break;
// furniture
//  elevator doors
case 'I':
case '[':
case ']': collision = c; break;}
return collision;}

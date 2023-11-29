#ifndef OGNS_H
#define OGNS_H

#define FLOOR_DEPTH 3
#define ITEM 0
#define OBSTACLE 1
#define FLOOR 2
//floor[ITEM][x][y] & type,quantityFINALLY
typedef int*** floor;
//items
//furniture & walls collision
//floor

floor* genfloor(void);
void dispfloor(floor*);
void delfloor(floor*);

#endif

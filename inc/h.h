#ifndef H_H
#define H_H
#include "list.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct{ int y, x; } vect;
typedef struct{
	int	h, m, s, d;
} TIME;

typedef struct{
	int	floorn;
	int	h, w, y, x;
	char	**buf;
	List	*characters;
} FLOOR;

typedef struct{
	int	floorn;
	int	door_open;
	FLOOR	*floor;
} ELEVATOR;

typedef struct{
	int	h, w;
	int	nfloor;
	FLOOR	**floor;
	ELEVATOR	*elevator;
	int	floorn;
	FLOOR	*currfloor;
} DUNGEON;

typedef struct{
	int	x, y, floorn;
	int	c;
	FLOOR	*currfloor;
} CHARACTER;

int	main2(void);
int	game(DUNGEON *dungeon, CHARACTER *player, TIME *time);

DUNGEON	*dungeon_new(int h, int w);
void	dungeon_free(DUNGEON *dungeon);
void	dungeon_add_stairs(DUNGEON *dungeon);
void	dungeon_add_elevators(DUNGEON *dungeon);
FLOOR	*floor_new(int floorn, int h, int w);
void	floor_free(FLOOR *floor);
ELEVATOR	*elevator_new(int y, int x, int floorn);

CHARACTER	*character_new(int y, int x, int floorn, FLOOR *floor, char c);
void	character_free(CHARACTER *character);
char	character_movement(FLOOR *floor, CHARACTER *character, vect v);
void	character_change_floor(FLOOR *old_floor, FLOOR *new_floor, CHARACTER *character);

void	time_add_s(TIME *t, int s);

// logic.c
vect	get_move_vector(char c);

// mechanic.c
int	check_collision(FLOOR *floor, int y, int x);

#endif

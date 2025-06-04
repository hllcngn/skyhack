#ifndef H_H
#define H_H
#include "list.h"
#include <stdlib.h>

typedef struct{ int y, x; } vect;

typedef struct{
	int	floorn;
	int	h, w;
	char	**buf;
	List	*characters;
} FLOOR;

typedef struct{
	int	h, w;
	int	nfloor;
	FLOOR	**floor;
} DUNGEON;

typedef struct{
	int	x, y;
	int	c;
} CHARACTER;

int	main2(void);
int	game(DUNGEON *dungeon, CHARACTER *player);

DUNGEON	*dungeon_new(int h, int w);
void	dungeon_free(DUNGEON *dungeon);
FLOOR	*floor_new(int floorn, int h, int w);
void	floor_free(FLOOR *floor);

CHARACTER	*character_new(int y, int x, char c);
void	character_free(CHARACTER *character);
void	character_movement(FLOOR *floor, CHARACTER *character, vect v);

// logic.c
vect	get_move_vector(char c);

// mechanic.c
int	check_collision(FLOOR *floor, int y, int x);

#endif

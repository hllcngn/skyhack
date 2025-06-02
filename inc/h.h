#ifndef H_H
#define H_H
#include <stdlib.h>

typedef struct{
	int	floorn;
	int	h, w;
	char	**buf;
} FLOOR;

typedef struct{
	int	h, w;
	int	nfloor;
	FLOOR	**floor;
} DUNGEON;

int	main2(void);
int	game(DUNGEON *dungeon);

#endif

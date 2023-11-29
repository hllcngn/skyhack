#ifndef OBJECTS_H
#define OBJECTS_H
#include "c2buf.h"

typedef struct{
	char foo;
} ENTITY;
typedef struct{
	char	id, nb;
	c2buf	*map;
} LEVEL;
typedef struct{
//	ENTITY	ents[20];
	LEVEL	*currlvl;
	LEVEL	**lvl;
} DUNGEON;

typedef struct{
	int	cl4ss;
	int	alignment;
} PLAYER;
typedef struct{
	int	total;
	int	ennemies_killed;
} SCORE;
typedef struct{
	char	symbol;
	vect	pos;
} CHARACTER;

#endif

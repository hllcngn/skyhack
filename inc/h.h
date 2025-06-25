#ifndef H_H
#define H_H
#include "list.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ncurses.h>//for debug

typedef struct{ int y, x; } vect;
typedef struct{ int d, h, m, s; } TIME;

typedef struct{
	int	floorn;
	int	h, w, y, x;
	char	**buf;
	List	*characters;
} FLOOR;

typedef struct{
	int	x, y;
	int	c;
	FLOOR	*currfloor;
} CHARACTER;

typedef struct{ //TODO rework
	int	door_open; //0,1,2
	FLOOR	*floor; //contains floor nb

	// SEE ALSO TODO.txt
	//char **elev_doors_closed,
	//     **elev_doors_broken;
	// ou
	//char **elev; //then change door depending on door status
	//int h,w;
	//
	//int *door_status; //door status for each floor
} ELEVATOR;

typedef struct{
	int	h, w;
	int	nfloor;
	FLOOR	**floor;
	ELEVATOR	*elevator;
	FLOOR	*currfloor;
} DUNGEON;

#include "stack.h"

int	main2(void);

int	game(List *stack, DUNGEON *dungeon, CHARACTER *player, TIME *time);

DUNGEON	*dungeon_new(int h, int w);
void	dungeon_free(DUNGEON *dungeon);
void	dungeon_add_stairs(DUNGEON *dungeon);
void	dungeon_add_elevators(DUNGEON *dungeon);

FLOOR	*floor_new(int floorn, int h, int w, int y, int x);
FLOOR	*floor_new_dungeon_floor(int floorn, int h, int w);
void	floor_free(FLOOR *floor);

ELEVATOR	*elevator_new(int floorn, int y, int x);
void	elevator_free(ELEVATOR *elev);
//void	elevator_call(DUNGEON* dungeon);
void	elevator_call(List **stack, TIME *time, void *null, DUNGEON* dungeon, void *null2);
void	elevator_handle_doorway(char k, char hit, DUNGEON *dungeon, CHARACTER *player);

CHARACTER	*character_new(int y, int x, FLOOR *floor, char c);
void	character_free(CHARACTER *character);
char	character_movement(FLOOR *floor, CHARACTER *character, vect v);
void	character_change_floor(FLOOR *new_floor, CHARACTER *character);

void	player_change_floor(DUNGEON *dungeon, FLOOR *floor_new, CHARACTER *player);
void	player_change_floor_stairs(DUNGEON *dungeon, CHARACTER* player, TIME *time, char stairs);

// mechanic.c
int	check_collision(FLOOR *floor, int y, int x);
void	handle_hit(List **stack, DUNGEON *dungeon, CHARACTER *player, char hit, char k);

// logic.c
vect	get_move_vector(char c);
void	time_add_s(TIME *t, int s);




void	player_movement(List **stack, TIME *time, void *player, DUNGEON *dungeon, void *k);

#endif

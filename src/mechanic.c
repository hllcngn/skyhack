#include "myncurses.h"
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

void	handle_hit(List **stack, DUNGEON *dungeon, CHARACTER *player, char hit, char k){
if (hit == 0 || hit == 1) return;
if ((hit == '[' || hit == ']' || hit == 'I')
		&& (k == 'w' || k == 'q' || k == 'e')){
	char c = ncurses_prompt_call_elevator(); //TODO call only if elevator isn't there
	if (c == 'y')
	list_add(stack, stack_new(5, NULL, &elevator_call, NULL));}
if ((hit == '[' || hit == ']' || hit == 'I')
		&& (k == 's' || k == 'z' || k == 'x')){
	int c = ncurses_prompt_elevator_select(dungeon);
	if (c == 0 && dungeon->elevator->door_open == 1)
		list_add(stack, stack_new(1, dungeon->elevator, &elevator_doors_close, NULL));
	else if (c == 0 && dungeon->elevator->door_open == 0)
		list_add(stack, stack_new(1, dungeon->elevator, &elevator_doors_open, NULL));
	else //if (dungeon->elevator->door_open == 1){
	{
		list_add(stack, stack_new(1, dungeon->elevator, &elevator_doors_close, NULL));
		int *c2 = malloc(sizeof(int)); *c2 = c;
		list_add(stack, stack_new(5, dungeon->elevator, &elevator_move, c2));
}
}
}

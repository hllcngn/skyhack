#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include "h.h"

typedef struct stack Stack;
struct stack{
	int	count;
	void	*obj;
	void	*param;
	void	(*f)(List**, void*, DUNGEON*, void*);
};

Stack	*stack_new(int count, void *obj,void (*f)(List**, void*, DUNGEON*, void*), void *param);
//void	stack_free(Stack *stack);
//void	stack_free_list(List *stack);

//void	stack_do(List *stack);
List	*stack_do(List **full_stack, List *stack_item, DUNGEON *dungeon);
void	full_stack_do(List **full_stack, DUNGEON *dungeon);
void	full_stack_pop_0(List **full_stack);

#endif

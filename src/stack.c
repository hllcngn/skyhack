#include "h.h"

Stack	*stack_new(int count, void *obj,
		void (*f)(List**, void*, DUNGEON*, void*), void *param){
Stack *new = malloc(sizeof(Stack));
new->count = count;
new->obj = obj;
new->param = param;
new->f = f;
return new;}

void	stack_free(List *stack){
//free(stack->param); //TODO check if this is working
free(stack->item);
list_free(stack);}


void	full_stack_do(List **full_stack, TIME *time,  DUNGEON *dungeon){
List *l = *full_stack;
time_add_s(time, 1);
while (l)
	l = stack_do(full_stack, l, time, dungeon);}

List	*stack_do(List **full_stack, List *stack_item, TIME *time, DUNGEON *dungeon){
if (stack_item == NULL || full_stack == NULL) return NULL;
int count = ((Stack*)(stack_item->item))->count;
count --;
if (count == 0){
	((Stack*)(stack_item->item))->f(
			full_stack,
			((Stack*)(stack_item->item))->obj,
			dungeon,
			((Stack*)(stack_item->item))->param);
	List *l = list_pop(full_stack, stack_item->item);
	return l->next;
	stack_free(stack_item);}
else	((Stack*)(stack_item->item))->count = count;
return stack_item->next;}

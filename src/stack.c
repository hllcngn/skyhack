#include "h.h"

Stack	*stack_new(int count, void *obj, void (*f)(List**, void*, DUNGEON*, void*), void *param){
Stack *new = malloc(sizeof(Stack));
new->count = count;
new->obj = obj;
new->param = param;
new->f = f;
return new;}

/*
void	stack_free(Stack *stack){
free(stack->param);
free(stack);}
*/


List	*stack_do(List **full_stack, List *stack_item, DUNGEON *dungeon){
if (stack_item == NULL || full_stack == NULL) return NULL;
int count = ((Stack*)(stack_item->item))->count;
count --;
if (count == 0){
	((Stack*)(stack_item->item))->f(full_stack,
		((Stack*)(stack_item->item))->obj, dungeon,
		((Stack*)(stack_item->item))->param);
	mvprintw(2, 0, "popping");
	List *l = list_pop(full_stack, stack_item->item); //< bug
	//return l->next;
	//stack_free(stack_item);}
}
else ((Stack*)(stack_item->item))->count = count;
return stack_item->next;
}

void	full_stack_do(List **full_stack, DUNGEON *dungeon){
int i = 0;
for (List *l = *full_stack; l; l = l->next){
		mvprintw(1, 0, "investigating element n#%d, with value %i", i, l);
		stack_do(full_stack, l, dungeon);
		if (l == NULL) mvprintw(3, 0, "l has become NULL"); refresh(); getch();
		i++;}
/*
	List *l = *full_stack;
	while (l)
		l = stack_do(full_stack, l, dungeon);
*/
}

void	full_stack_pop_0(List **full_stack){
if (*full_stack == NULL) return;
if ((*full_stack)->next == NULL){
	if (((Stack*)(*full_stack))->count == 0)
		list_pop(full_stack, *full_stack); return;}
if (((Stack*)((*full_stack)->next))->count == 0) list_pop(full_stack, (*full_stack)->next);
full_stack_pop_0(&((*full_stack)->next));
}

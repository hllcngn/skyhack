#ifndef LIST_H
#define LIST_H
#include <stdlib.h>

typedef struct list List;
struct list{
	void	*item;
	List	*next;
};

List	*list_new(void *item);
void	list_push_front(List **list, List *new);
void	list_add(List **list, void *item);
List	*list_pop(List **list, void *item);
void	list_free(List *list);

void	list_do(List *list, void (*f)(List*));

#endif

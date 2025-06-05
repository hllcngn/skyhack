#include "list.h"

List	*list_new(void *item){
List *new = malloc(sizeof(List));
new->next = NULL;
new->item = item;
return new;}

void	list_push_front(List **list, List *new){
new->next = *list;
*list = new;}

void	list_add(List **list, void *item){
List *new = list_new(item);
list_push_front(list, new);}

List	*list_pop(List **list, void *item){
if ((*list)->item == item){
	List *l = *list;
	*list = (*list)->next;
	return l;}
for (List *l = (*list)->next, *l2 = *list; l; l = l->next){
	if (l->item = item){
		l2->next = l->next;
		return l;}
	l2 = l;}
return NULL;}

void	list_free(List *list){
if (list == NULL) return;
list_free(list->next);
free(list);}

void	list_do(List *list, void (*f)(List*)){
for (List *l = list; l; l = l->next)
	f(l);}

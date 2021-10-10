#include"list.h"
#include<stdio.h>
#include<stdlib.h>

struct list* list_create()
{
    struct list* my_list = malloc(sizeof(struct list));
    struct link* my_first_link = malloc(sizeof(struct link));
    my_list->head = my_first_link;
    my_list->capacity = 0;
    my_list->size = 1;

    my_first_link->data = NULL;
    my_first_link->next = NULL;
    return my_list;
}
void list_free(struct list* _list)
{
    free(_list);
    free(_list->head);
}
void list_insert()
{

}
void list_remove()
{

}
void list_position()
{

}
void list_reverse()
{

}

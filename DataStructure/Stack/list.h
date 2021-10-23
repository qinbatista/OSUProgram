
#ifndef __LIST_H
#define __LIST_H

struct link
{
    void *data;
    struct link *next;
    struct link *previous;
};
struct list
{
    struct link* head;
    int size;
};
struct list;

struct list* list_create();
void list_free(struct list* list);
void list_insert(struct list* list, void* val);
void list_remove(struct list* list, void* val, int (*cmp)(void* a, void* b));
int list_position(struct list* list, void *val, int (*cmp)(void* a, void* b));
void list_reverse(struct list* list);

int remove_function(void* a, void* b);
void list_remove_index(struct list* _list, int _index);
void list_print(struct list* _list);
#endif
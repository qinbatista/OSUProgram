#include"list.h"
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct list* list_create()
{
    struct list* my_list = malloc(sizeof(struct list));
    struct link* my_first_link = malloc(sizeof(struct link));
    my_list->head = my_first_link;
    my_list->size = 0;

    // my_first_link->data = NULL;
    // my_first_link->next = NULL;
    return my_list;
}
void list_free(struct list* _list)
{
    int size = _list->size;
    for(int i = 0; i< size; i++)
    {
        _list = list_remove_index(_list,0);
    }
    free(_list);
    printf("[list_free] %p\n",_list);
}
struct list* list_insert(struct list* _list, void *data)
{
    struct link *temp_link;
    temp_link = _list->head;
    while(temp_link->next!=NULL)
    {
        temp_link = temp_link->next;//find last link
    }
    temp_link->data = data;
    temp_link->next = malloc(sizeof(struct link));
    _list->size++;
    return _list;
}
struct list* list_remove(struct list* _list, void *data)
{
    int index = 0;
    struct link *temp_link = _list->head;
    struct link *prev_link = _list->head;
    // printf("data = %s\n",data);
    while(1)
    {
        if(index >= _list->size)
        {
            printf("[list_remove]can't find *data\n");
            break;
        }
        // printf("temp_link = %s\n",temp_link->data);
        if(!strncmp(temp_link->data, data,128))
        {
            if(index == 0)
            {
                struct link* headlink =  _list->head->next;
                free(_list->head);
                _list->head = headlink;
                _list->size--;
                // printf("[list_remove]delete first link\n");
                break;
            }
            else
            {
                // printf("prev_link->next = %s\n",prev_link->data);
                // printf("find\n");
                prev_link->next = temp_link->next;
                // printf("prev_link->data = %s\n",prev_link->data);
                // printf("prev_link->next->data = %s\n",prev_link->next->data);
                _list->size--;
                free(temp_link);
                break;
            }
        }
        prev_link = temp_link;
        temp_link = temp_link->next;
        // printf("new temp_link = %s\n",temp_link->data);
        index++;
    }
    return _list;
}
struct list* list_remove_index(struct list* _list, int _index)
{
    int index = 0;
    struct link *temp_link = _list->head;
    struct link *prev_link = _list->head;
    // printf("_list->size = %d\n",_list->size);
    if(_index>=_list->size)
    {
        printf("[list_remove_index] index over the size\n");
        return _list;
    }
    // printf("_index = %d\n",_index);
    // printf("list->data = %s\n",_list->head->data);
    // printf("list->next->data = %s\n",_list->head->next->data );
    // printf("list->next->next->data = %s\n",_list->head->next->next->data );
    printf("-----\n");
    while(1)
    {
        printf("-----\n");

        if(index == _index)
        {
            if(_index == 0)
            {
                struct link* headlink =  _list->head->next;
                free(_list->head);
                _list->head = headlink;
                _list->size--;
                // printf("[list_remove_index]delete first link\n");
            }
            else
            {
                printf("aaaa=%d\n",index);
                printf("prev_link->next = %s\n",prev_link->data);
                // printf("find\n");
                prev_link->next = temp_link->next;
                // printf("prev_link->data = %s\n",prev_link->data);
                // printf("prev_link->next->data = %s\n",prev_link->next->data);
                _list->size--;
                free(temp_link);
            }
            break;
        }
        // printf("-index = %d\n",index);
        // printf("-prev_link->data = %s\n",prev_link->data);
        // printf("-prev_link->next->data = %s\n",prev_link->next->data );
        // printf("-prev_link->next->next->data = %s\n",prev_link->next->next->data );
        prev_link = temp_link;
        temp_link = temp_link->next;
        // printf("new temp_link = %s\n",temp_link->data);
        index++;
        // printf("+index = %d\n",index);
        // printf("+prev_link->data = %s\n",prev_link->data);
        // printf("+prev_link->next->data = %s\n",prev_link->next->data );
        // printf("+prev_link->next->next->data = %s\n",prev_link->next->next->data );
        // printf("-----\n");

    }
    return _list;
}
int list_position(struct list* _list, void *data)
{
    int index = 0;
    struct link *temp_link = _list->head;
    struct link *prev_link = _list->head;
    // printf("data = %s\n",data);
    while(1)
    {
        if(index >= _list->size)
        {
            printf("[list_remove]can't find *data\n");
            return -1;
        }
        // printf("temp_link = %s\n",temp_link->data);
        if(!strncmp(temp_link->data, data,128))
        {
            return index;
        }
        prev_link = temp_link;
        temp_link = temp_link->next;
        // printf("new temp_link = %s\n",temp_link->data);
        index++;
    }
    return index;
}

struct list* list_reverse(struct list* _list)
{
    struct list *new_link = list_create();
    struct link *last_link = _list->head;
    
    // for(int i = 0; i<_list->size-1; i++)
    // {
    //     printf("last_link=%s\n",last_link->data);
    //     last_link = last_link->next;
    // }
    // printf("_list->size=%d\n",_list->size);
    // struct link *temp_link = _list->head;
    // for(int i = _list->size; i>=0; i--)
    // {
    //     printf("i=%d\n",i);
    //     temp_link = _list->head;
    //     for(int j = i; j>0; j--)
    //     {
    //         temp_link = temp_link->next;
    //     }
    //     new_link = list_insert(temp_link)
    // }
    return _list;
}

void list_print(struct list* _list)
{

    printf("[list_print] %d\n",_list->size);
    if(_list==NULL)
    {
        printf("[list info] _list = NULL\n");
        printf("[list info] size = %d\n",_list->size);
        return;
    }
    struct link *temp_link = _list->head;
    int index = 0;
    while(temp_link->next!=NULL)
    {
        printf("[%d] %s\n",index,temp_link->data);
        temp_link = temp_link->next;
        index++;
    }
    printf("[list info] size = %d\n",_list->size);
}


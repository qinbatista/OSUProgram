#include"list.h"
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct list
{
    struct link* head;
    int size;
};
struct list* list_create()
{
    struct list* my_list = malloc(sizeof(struct list));
    struct link* my_first_link = malloc(sizeof(struct link));
    my_list->head = my_first_link;
    my_list->size = 0;

    my_first_link->data = NULL;
    my_first_link->next = NULL;
    my_first_link->previous = NULL;
    return my_list;
}
void list_free(struct list* _list)
{
    int size = _list->size;
    for(int i = 0; i< size; i++)
    {
        list_remove_index(_list,0);
    }
    free(_list);
    printf("[list_free] %p\n",_list);
}
void list_insert(struct list* _list, void *data)
{
    struct link *temp_link =  _list->head;
    struct link *previous_link =  malloc(sizeof(struct link));
    while(temp_link->next!=NULL)
    {
        // printf("2\n");
        // printf("temp_link->data=%s\n",temp_link->data);
        previous_link = temp_link;
        temp_link = temp_link->next;//find last link
        // printf("temp_link->next->data=\n",temp_link->next->data);
    }
    // printf("data=%s\n",data);
    temp_link->data = data;
    temp_link->next = malloc(sizeof(struct link));
    temp_link->next->data = NULL;
    temp_link->next->next = NULL;
    temp_link->previous = previous_link;
    _list->size++;
    printf("temp_link->data=%s\n",temp_link->data);
    printf("temp_link->previous->data=%s\n",temp_link->previous->data);
    printf("-----\n");
}
int remove_function(void* a, void* b)
{   
    // printf("1%s\n",a);
    // printf("2%s\n",b);
    if(!strncmp(a, b,128))
    {
        return 0;
        printf("found!\n");
    }
    else
    {
        return -1;
        printf("can't find!\n");
    }
}
void list_remove(struct list* _list, void *data,int (*cmp)(void* a, void* b))
{
    int index = 0;
    struct link *temp_link = _list->head;
    struct link *prev_link = _list->head;
    // printf("data = %s\n",data);
    while(1)
    {
        if(index >= _list->size)
        {
            // printf("[list_remove]can't find *data\n");
            break;
        }
        // printf("temp_link = %s\n",temp_link->data);
        if(!cmp(temp_link->data, data))
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
    // return _list;
}
void list_remove_index(struct list* _list, int _index)
{
    int index = 0;
    struct link *temp_link = _list->head;
    struct link *prev_link = _list->head;
    // printf("_list->size = %d\n",_list->size);
    if(_index>=_list->size)
    {
        printf("[list_remove_index] index over the size\n");
        // return _list;
    }
    // printf("_index = %d\n",_index);
    // printf("list->data = %s\n",_list->head->data);
    // printf("list->next->data = %s\n",_list->head->next->data );
    // printf("list->next->next->data = %s\n",_list->head->next->next->data );
    // printf("-----\n");
    while(1)
    {
        // printf("-----\n");

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
    // return _list;
}
int list_position(struct list* list, void* val, int (*cmp)(void* a, void* b))
{
    int index = 0;
    struct link *temp_link = list->head;
    struct link *prev_link = list->head;
    // printf("data = %s\n",data);
    while(1)
    {
        if(index >= list->size)
        {
            printf("[list_remove]can't find *data\n");
            return -1;
        }
        // printf("temp_link = %s\n",temp_link->data);
        // if(!strncmp(temp_link->data, val,128))
        if(!cmp(temp_link->data,val))
        {
            // printf()
            return index;
        }
        prev_link = temp_link;
        temp_link = temp_link->next;
        // printf("new temp_link = %s\n",temp_link->data);
        index++;
    }
    return index;
}

void list_reverse(struct list* _list)
{
    struct list* new_link = list_create();
    struct link *cur_link = _list->head;
    for(int i = _list->size; i>0; i--)
    {
        cur_link = _list->head;
        for(int j = i-1; j>0; j--)
        {
            if(cur_link->next!=NULL)
                cur_link = cur_link->next;
        }
        // printf("[reversing data] = %s\n",cur_link->data);
        list_insert(new_link,cur_link->data);
        free(cur_link);
    }
    
    _list->head = new_link->head;
    _list->size = new_link->size;
    free(new_link);
    // printf("new_link->head->data=%s\n",new_link->head->data);
    // printf("new_link->head->next->data=%s\n",new_link->head->next->data);
    // printf("new_link->head->next->next->data=%s\n",new_link->head->next->next->data);
    // return new_link;
}

void list_print(struct list* _list)
{
    printf("[List Info] size = %d:\n",_list->size);
    if(_list==NULL)
    {
        printf("[list info] _list = NULL\n");
        return;
    }
    // printf("2\n");
    struct link *temp_link = _list->head;
    int index = 0;
    // printf("2.2\n");
    while(temp_link->next!=NULL)
    {
        // printf("3\n");
        printf("[%d] %s\n",index,temp_link->data);
        temp_link = temp_link->next;
        index++;
        // printf("4\n");
    }
    
}


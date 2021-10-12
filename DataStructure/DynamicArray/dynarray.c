#include"dynarray.h"
#include<stdio.h>
#include<stdlib.h>
struct dynarray* dynarray_create()
{
    struct dynarray* this_array = malloc(sizeof(struct dynarray));
    this_array->size = 1;
    this_array->capacity_index = 0;
    return this_array;
}
struct dynarray* expand_dynarray(int size)
{
    struct dynarray* this_array = malloc(size * sizeof(struct dynarray));
    this_array->size = size;
    this_array->capacity_index = 0;
    return this_array;
}
void dynarray_free(struct dynarray* array)
{
    free(array);
}
int dynarray_size(struct dynarray* array)
{
    return array->size;
}
void dynarray_insert(struct dynarray** array, void* data)
{
    if((*array)->size > (*array)->capacity_index)
    {
        // printf("capacity is enough, add data to last\n");
        (*array)[(*array)->capacity_index].data = data;
        (*array)->capacity_index = (*array)->capacity_index+1;
        // expanded_array = array;
        // printf("no array->size = %d\n", array->size);
        // printf("no array->capacity_index = %d\n", array->capacity_index);
    }
    else
    {
        struct dynarray* expanded_array;
        printf("not enough capacity, create a new array\n");
        expanded_array = expand_dynarray((*array)->size*2);
        for(int i = 0; i < (*array)->capacity_index+1; i++)
        {
            if(i == (*array)->capacity_index)
            {
                // printf("[%d]add new:%d\n",i,*((int *)(data)));
                expanded_array[i].data = data;
                expanded_array->capacity_index = (*array)->capacity_index+1;
            }
            else
            {
                // printf("[%d]copying old:%d\n",i,*((int *)(array[i].data)));
                expanded_array[i].data = (*array)[i].data;
            }
        }
        *array = expanded_array;
        // free(array);
        printf("B:expanded_array=%p\n",expanded_array);
        printf("B:array=         %p\n",array);
        // free(array);
        printf("A:expanded_array=%p\n",expanded_array);
        printf("A:array=         %p\n",array);
    }
    // printf("expanded_array->size = %d\n", expanded_array->size);
    // printf("expanded_array->capacity_index = %d\n", expanded_array->capacity_index);
    // for(int i = 0; i< expanded_array->capacity_index; i++)
    // {
    //     printf("[%d]expanded_array=%d\n",i, *(int *)(expanded_array[i].data));
    // }
}
void dynarray_remove(struct dynarray* array, int remove_index)
{
    if(array->capacity_index>=remove_index)
    {
        for(int i = 0; i <= array->capacity_index; i++)
        {
            if(i >= remove_index)
            {
                array[i].data = array[i+1].data;
            }
        }
        array[array->capacity_index].data = NULL;
        array->capacity_index--;
    }
    else
    {
        printf("[dynarray_remove]remove_index is bigger than capacity");
    }
    // return array;
}
void* dynarray_get(struct dynarray* array, int index)
{
    void *data = NULL;
    if(index<array->capacity_index)
        data = array[index].data;
    else
        printf("[dynarray_get]index is bigger than capacity\n");
    return data;
}
void dynarray_set(struct dynarray* array, int index, void *value)
{
    if(index<array->capacity_index)
        array[index].data = value;
    else
        printf("[dynarray_set]index is bigger than capacity\n");
    // return array;
}
void dynarray_print(struct dynarray* this_array)
{
    printf("[Array Info] size = %d, used = %d\n",this_array->size,this_array->capacity_index);
    // printf("used = %d\n",this_array->capacity_index);
}
void test_input()
{
    struct dynarray* this_array = malloc(sizeof(struct dynarray));
    // printf("aaaa\n");
}


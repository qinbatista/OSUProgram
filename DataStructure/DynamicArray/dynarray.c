#include"dynarray.h"
#include<stdio.h>
#include<stdlib.h>
struct Myarray* dynarray_create()
{
    struct Myarray* this_array = malloc(sizeof(struct Myarray));
    this_array->size = 1;
    this_array->capacity_index = 0;
    return this_array;
}
struct Myarray* expand_dynarray(int size)
{
    struct Myarray* this_array = malloc(size * sizeof(struct Myarray));
    this_array->size = size;
    this_array->capacity_index = 0;
    return this_array;
}
void dynarray_free(struct Myarray* array)
{
    free(array);
}
int dynarray_size(struct Myarray* array)
{
    return array->size;
}
struct Myarray* dynarray_insert(struct Myarray* array, void* data)
{
    struct Myarray* expanded_array;
    if(array->size > array->capacity_index)
    {
        // printf("capacity is enough, add data to last\n");
        array[array->capacity_index].data = data;
        array->capacity_index = array->capacity_index+1;
        expanded_array = array;
        // printf("no array->size = %d\n", array->size);
        // printf("no array->capacity_index = %d\n", array->capacity_index);
    }
    else
    {
        // printf("not enough capacity, create a new array\n");
        expanded_array = expand_dynarray(array->size*2);
        for(int i = 0; i < array->capacity_index+1; i++)
        {
            if(i == array->capacity_index)
            {
                // printf("[%d]add new:%d\n",i,*((int *)(data)));
                expanded_array[i].data = data;
                expanded_array->capacity_index = array->capacity_index+1;
            }
            else
            {
                // printf("[%d]copying old:%d\n",i,*((int *)(array[i].data)));
                expanded_array[i].data = array[i].data;
            }
        }
        
        
        free(array);
    }
    // printf("expanded_array->size = %d\n", expanded_array->size);
    // printf("expanded_array->capacity_index = %d\n", expanded_array->capacity_index);
    // for(int i = 0; i< expanded_array->capacity_index; i++)
    // {
    //     printf("[%d]expanded_array=%d\n",i, *(int *)(expanded_array[i].data));
    // }
    // printf("-----\n");
   
    return expanded_array;
}
void dynarray_remove(struct Myarray* array, int remove_index)
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
void* dynarray_get(struct Myarray* array, int index)
{
    void *data = NULL;
    if(index<array->capacity_index)
        data = array[index].data;
    else
        printf("[dynarray_get]index is bigger than capacity\n");
    return data;
}
void dynarray_set(struct Myarray* array, int index, void *value)
{
    if(index<array->capacity_index)
        array[index].data = value;
    else
        printf("[dynarray_set]index is bigger than capacity\n");
    // return array;
}
void dynarray_print(struct Myarray* this_array)
{
    printf("[Array Info] size = %d, used = %d\n",this_array->size,this_array->capacity_index);
    // printf("used = %d\n",this_array->capacity_index);
}
void test_input()
{
    struct Myarray* this_array = malloc(sizeof(struct Myarray));
    // printf("aaaa\n");
}


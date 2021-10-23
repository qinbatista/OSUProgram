#include"dynarray.h"
#include<stdio.h>
#include<stdlib.h>
struct dynarray* dynarray_create()
{
    struct dynarray* this_array = malloc(sizeof(struct dynarray));
    this_array->size = 1;
    this_array->capacity = 0;
    this_array->data = (void **)malloc(this_array->size * sizeof(void*));
    return this_array;
}

void dynarray_free(struct dynarray* da)
{
    free(da->data);
    free(da);
}
int dynarray_size(struct dynarray* da)
{
    return da->size;
}
struct dynarray* expand_dynarray(struct dynarray* array,int size)
{
    // struct dynarray* this_array = malloc(size * sizeof(struct dynarray));
    void **temp = (void **)malloc(size*2 * sizeof(void*));
    for (int i = 0; i<array->capacity; i++)
    {
        // if(i%2 == 0)
        //     printf("temp[%d]=%d\n",i,*((int*)(array->data[i])));
        // else
        //     printf("temp[%d]=%s\n",i,array->data[i]);
        temp[i] = array->data[i];
    }
    // for (int i = 0; i<size; i++)
    // {
    //     array->data[i] = temp[i];
    // }
    // free(*(array->data));
    array->size = size*2;
    array->data = temp;
    // for (int i = 0; i<size; i++)
    // {
    //     array->data
    // }
    // printf("enough:size = %d, capacity = %d\n",array->size, array->capacity);
    // for(int i = 0; i< array->capacity; i++)
    // {
    return array;
}
void dynarray_insert(struct dynarray* da, void* data)
{
    if(da->size > da->capacity)
    {
        // printf("enough:size = %d, capacity = %d\n",da->size, da->capacity);
        // printf("enough:data int = %s\n", data);
        // printf("1enough data = %d\n", *((int *)data));
        // printf("1enough:da->data[0] = %d\n", (int)da->data[0]);
        da->data[da->capacity] = data;
        da->capacity = da->capacity+1;
        // printf("2enough:da->data[0] = %d\n", *((int*)da->data[0]));
        // printf("2enough:da->data[1] = %d\n", (int)da->data[1]);
    }
    else
    {
        // printf("expanding:size = %d, capacity = %d\n",da->size, da->capacity);
        int current_capacity = da->capacity;
        da = expand_dynarray(da, da->size);
        da->data[current_capacity] = data;
        da->capacity = da->capacity+1;
    }
    // for(int i = 0; i< da->capacity; i++)
    // {
    //     if(i%2 == 0)
    //         printf("[%d]data=%d\n",i,*((int *)(da->data[i])));
    //     else
    //         printf("[%d]data=%s\n",i, da->data[i]);
    // }
    // printf("----\n");
}
void dynarray_remove(struct dynarray* da, int remove_index)
{
    if(da->capacity>=remove_index)
    {
        for(int i = 0; i <= da->capacity; i++)
        {
            if(i >= remove_index)
            {
                da->data[i] = da->data[i+1];
            }
        }
        da->data[da->capacity] = NULL;
        da->capacity--;
    }
    else
    {
        printf("[dynarray_remove]remove_index is bigger than capacity\n");
    }
    // return array;
}
void* dynarray_get(struct dynarray* da, int index)
{
    void *data = NULL;
    if(index<da->capacity)
        data = da->data[index];
    else
        printf("[dynarray_get]index is bigger than capacity\n");
    return data;
}
void dynarray_set(struct dynarray* da, int index, void *value)
{
    if(index<da->capacity)
        da->data[index] = value;
    else
        printf("[dynarray_set]index is bigger than capacity\n");
    // return array;
}
void dynarray_print(struct dynarray* da)
{
    printf("[Array Info] size = %d, used = %d\n",da->size,da->capacity);
    // printf("used = %d\n",this_array->capacity);
}
void test_input()
{
    struct dynarray* da = malloc(sizeof(struct dynarray));
    // printf("aaaa\n");
}


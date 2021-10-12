//gcc --std=c99 -o out main.c dynarray.c  
#include<stdlib.h>
#include<stdio.h>
#include "dynarray.h"
int main()
{
    struct Myarray* my_array = dynarray_create();
    dynarray_size(my_array);
    printf("array size = %d\n", dynarray_size(my_array));
    char *data_char = "this is data";
    int array_size = 8;
    printf("[1my_array] my_array=%p\n",my_array);
    //insert int, string, int, string, int, string...
    for(int i = 0; i< array_size; i++)
    {
        if(i%2 == 0)
        {
            int *number = malloc(sizeof(int));
            *number = i;
            void *data_int_temp = number;
            printf("data_int_temp = %d\n",*((int *)(data_int_temp)));
            dynarray_insert(&my_array, data_int_temp);
        }
        else
            dynarray_insert(&my_array, data_char);

        printf("[my_array] my_array=%p\n",my_array);
    }
    printf("------dynarray_insert=%p\n",my_array);
    dynarray_print(my_array);
    //delete int, string
    for(int i = 0; i< array_size; i++)
    {
        if(i%2 == 0)
            printf("[%d]data=%d\n",i,*((int *)(my_array[i].data)));
        else
            printf("[%d]data=%s\n",i, my_array[i].data);
    }
    printf("-----------------\n");
    dynarray_remove(my_array,3);
    dynarray_remove(my_array,3);
    for(int i = 0; i< array_size-2; i++)
    {
        if(i%2 == 0)
            printf("[%d]data=%d\n",i, *(int *)(my_array[i].data));
        else
            printf("[%d]data=%s\n",i, my_array[i].data);
    }
    void *get_data = dynarray_get(my_array,8);
    if(get_data!=NULL)
        printf("get number=%d\n",*((int *)(get_data)));
    get_data = dynarray_get(my_array,1);
    if(get_data!=NULL)
        printf("get data=%s\n",get_data);
    printf("-----------------\n");

    char *data_char_new = "this is a new data";
    int int_new = 999;
    dynarray_set(my_array, 0, &int_new);
    dynarray_set(my_array, 5, data_char_new);

    for(int i = 0; i< array_size-2; i++)
    {
        if(i%2 == 0)
            printf("[%d]data=%d\n",i, *(int *)(my_array[i].data));
        else
            printf("[%d]data=%s\n",i, my_array[i].data);
    }

    dynarray_free(my_array);
    return 0;
}
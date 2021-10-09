#include"dynarray.h"
#include<stdio.h>
#include<stdlib.h>
struct Myarray* dynarray_create()
{
    struct Myarray* this_array = malloc(sizeof(struct Myarray));
    return this_array;
}
void dynarray_free(struct Myarray* arrary)
{
    free(arrary);
}
void test_input()
{
    struct Myarray* this_array = malloc(sizeof(struct Myarray));
    printf("aaaa\n");
}


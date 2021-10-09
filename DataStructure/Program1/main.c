//gcc --std=c99 -o out main.c dynarray.c  
#include<stdlib.h>
#include<stdio.h>
#include "dynarray.h"
int main()
{
    struct Myarray* my_array = dynarray_create();

    dynarray_free(my_array);
    test_input();
    return 0;
}
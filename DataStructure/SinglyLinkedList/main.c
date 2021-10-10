//gcc --std=c99 -o out main.c list.c  
#include<stdlib.h>
#include<stdio.h>
#include "list.h"
int main()
{
    struct list* _list = list_create();
    list_free(_list);
    return 0;
}
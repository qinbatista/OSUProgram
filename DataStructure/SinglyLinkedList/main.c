//gcc --std=c99 -o out main.c list.c  
#include<stdlib.h>
#include<stdio.h>
#include "list.h"
int main()
{
    struct list* _list = list_create();
    //string can't bigger than 128bit
    char *string0 = "a";
    _list = list_insert(_list,string0);
    char *string1 = "b";
    _list = list_insert(_list,string1);
    char *string2 = "c";
    _list = list_insert(_list,string2);
    char *string3 = "d";
    _list = list_insert(_list,string3);
    char *string4 = "e";
    _list = list_insert(_list,string4);
    list_print(_list);

    char *compare_sting = "a";
    _list = list_remove(_list, compare_sting);
    char *compare_sting1 = "c";
    _list = list_remove(_list, compare_sting1);
    _list = list_remove_index(_list, 0);
    char *compare_sting3 = "aa";
    _list = list_remove(_list, compare_sting3);
    _list = list_remove_index(_list, 2);
    list_print(_list);

    // char *list_p_char = "b";
    // printf("[position]=%d\n",list_position(_list,list_p_char));

    // _list = list_reverse(_list);
    // list_print(_list);
    // list_free(_list);
    // list_print(_list);
    return 0;
}
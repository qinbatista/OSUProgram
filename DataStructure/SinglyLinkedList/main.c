//gcc --std=c99 -o out main.c list.c  
#include<stdlib.h>
#include<stdio.h>
#include "list.h"
int main()
{
    struct list* _list = list_create();
    char *string0 = "a";
    printf("1\n");
    list_insert(_list,string0);
    printf("1\n");
    char *string1 = "b";
    list_insert(_list,string1);
    printf("1\n");
    char *string2 = "c";
    list_insert(_list,string2);
    char *string3 = "d";
    list_insert(_list,string3);
    printf("1\n");
    char *string4 = "e";
    list_insert(_list,string4);
    char *string5 = "f";
    list_insert(_list,string5);
    char *string6 = "g";
    list_insert(_list,string6);
    list_print(_list);
    printf("1\n");
    list_reverse(_list);
    list_print(_list);



    char *compare_sting = "a";
    int (* func)(void *a, void *b);
    func = &remove_function;
    list_remove(_list, compare_sting, func);
    char *compare_sting1 = "c";
    list_remove(_list, compare_sting1,func);
    list_remove_index(_list, 0);
    char *compare_sting3 = "aa";
    list_remove(_list, compare_sting3,func);
    list_remove_index(_list, 2);
    list_print(_list);

    char *list_p_char = "b";
    printf("[position]=%d\n",list_position(_list,list_p_char,func));

    // _list = list_reverse(_list);
    // list_print(_list);
    list_reverse(_list);
    list_print(_list);
    return 0;
}
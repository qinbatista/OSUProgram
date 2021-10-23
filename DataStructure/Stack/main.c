//gcc --std=c99 -o out main.c list.c stack.c  
#include<stdlib.h>
#include<stdio.h>
#include"stack.h"
int main()
{
    struct stack* this_stack = stack_create();
    char *data_char = "this is data";
    int array_size = 4;
    // if(stack_isempty(this_queue))
    printf("stack_isempty(this_stack)=%d\n",stack_isempty(this_stack));
    // else
        // printf("is not empty\n");
    for(int i = 0; i< array_size; i++)
    {
        if(i%2 == 0)
        {
            int *number = malloc(sizeof(int));
            *number = i;
            void *data_int_temp = number;
            printf("[insert]%d\n",*((int *)(data_int_temp)));
            stack_push(this_stack, data_int_temp);
        }
        else
        {
            printf("[insert]%s\n",data_char);
            stack_push(this_stack, data_char);
        }
        // printf("[my_array] my_array=%p\n",my_array);
    }
    stack_print(this_stack);
    stack_pop(this_stack);
    printf("stack's top = %d\n",*((int *)stack_top(this_stack)));
    stack_pop(this_stack);
    printf("stack's top = %s\n",stack_top(this_stack));
    stack_pop(this_stack);
    printf("stack's top = %d\n",*((int *)stack_top(this_stack)));
    stack_pop(this_stack);
    printf("stack's top = %s\n",stack_top(this_stack));
    stack_print(this_stack);
    printf("stack_isempty(this_queue)=%d\n",stack_isempty(this_stack));
    stack_free(this_stack);
    return 0;
}
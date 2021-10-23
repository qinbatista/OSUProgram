//gcc --std=c99 -o out main.c dynarray.c Stack.c  
#include<stdlib.h>
#include<stdio.h>
#include"stack.h"
int main()
{
    struct queue* this_stack = stack_create();
    char *data_char = "this is data";
    int array_size = 4;
    // if(queue_isempty(this_queue))
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
            queue_enqueue(this_stack, data_int_temp);
        }
        else
        {
            printf("[insert]%s\n",data_char);
            queue_enqueue(this_stack, data_char);
        }
        // printf("[my_array] my_array=%p\n",my_array);
    }
    queue_dequeue(this_stack);
    printf("queue's frond = %d\n",*((int *)queue_front(this_stack)));

    queue_dequeue(this_stack);
    printf("queue's frond = %s\n",queue_front(this_stack));

    queue_dequeue(this_stack);
    printf("queue's frond = %d\n",*((int *)queue_front(this_stack)));

    queue_dequeue(this_stack);
    // printf("queue's frond = %s\n",queue_front(this_queue));

    queue_print(this_stack);

    printf("queue_isempty(this_queue)=%d\n",queue_isempty(this_stack));
    queue_free(this_stack);
    return 0;
}
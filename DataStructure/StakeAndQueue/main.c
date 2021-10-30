//gcc --std=c99 -o out main.c dynarray.c queue.c  
#include<stdlib.h>
#include<stdio.h>
#include"queue.h"
int main()
{
    struct queue* this_queue = queue_create();
    char *data_char = "this is data";
    int array_size = 4;
    printf("queue_isempty(this_queue)=%d\n",queue_isempty(this_queue));
    // // // else
    // //     // printf("is not empty\n");
    for(int i = 0; i< array_size; i++)
    {
        if(i%2 == 0)
        {
            int *number = malloc(sizeof(int));
            *number = i;
            void *data_int_temp = number;
            printf("[insert]%d\n",*((int *)(data_int_temp)));
            queue_enqueue(this_queue, data_int_temp);
        }
        else
        {
            printf("[insert]%s\n",data_char);
            queue_enqueue(this_queue, data_char);
        }
    }
    printf("queue's front = %d\n",*((int *)queue_front(this_queue)));
    // printf("queue's front = %s\n",queue_front(this_queue));
    // // stack_print(this_stack);
    
    printf("queue:%d\n",*((int *)queue_dequeue(this_queue)));
    printf("queue:%s\n",queue_dequeue(this_queue));
    // printf("queue:%s\n",queue_dequeue(this_queue));
    printf("queue's front = %d\n",*((int *)queue_front(this_queue)));
    printf("queue's front = %s\n",queue_front(this_queue));
    // printf("queue:%d\n",*((int *)queue_dequeue(this_queue)));
    // stack_pop(this_stack);
    // printf("stack's top = %s\n",stack_top(this_stack));
    // stack_pop(this_stack);
    // printf("stack's top = %d\n",*((int *)stack_top(this_stack)));
    // stack_pop(this_stack);
    // printf("stack's top = %s\n",stack_top(this_stack));
    // // stack_print(this_stack);
    // // printf("stack_isempty(this_queue)=%d\n",stack_isempty(this_stack));
    // stack_free(this_stack);
    return 0;
}
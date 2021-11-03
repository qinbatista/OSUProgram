//gcc --std=c99 -o out main.c dynarray.c queue.c  
#include<stdlib.h>
#include<stdio.h>
#include"queue.h"
int main()
{
    struct queue* this_queue = queue_create();
    char *data_char = "this is data";
    int array_size = 3;
    // if(queue_isempty(this_queue))
    printf("queue_isempty(this_queue)=%d\n",queue_isempty(this_queue));
    // else
        // printf("is not empty\n");
    for(int i = 0; i< array_size; i++)
    {
        int *number = malloc(sizeof(int));
        *number = i;
        void *data_int_temp = number;
        printf("[insert]%d\n",*((int *)(data_int_temp)));
        queue_enqueue(this_queue, data_int_temp);
    }
    queue_dequeue(this_queue);
    // printf("queue's front = %d\n",*((int *)queue_front(this_queue)));
    printf("-------\n");
    queue_dequeue(this_queue);
    // printf("queue's front = %d\n",*((int *)queue_front(this_queue)));
    printf("-------\n");
    queue_dequeue(this_queue);
    // printf("queue's front = %d\n",*((int *)queue_front(this_queue)));
    printf("-------\n");
    // queue_dequeue(this_queue);
    // printf("queue's front = %d\n",*((int *)queue_front(this_queue)));
    // printf("queue's front = %s\n",queue_front(this_queue));
    // printf("-------\n");
    // queue_print(this_queue);
    printf("queue_isempty(this_queue)=%d\n",queue_isempty(this_queue));
    queue_free(this_queue);
    return 0;
}
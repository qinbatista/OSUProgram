/*
 * This file is where you should implement your queue.  It already contains
 * skeletons of the functions you need to implement (along with documentation
 * for each function).  Feel free to implement any additional functions you
 * might need.  Also, don't forget to include your name and @oregonstate.edu
 * email address below.
 *
 * Name:
 * Email:
 */

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "dynarray.h"

/*
 * This is the structure that will be used to represent a queue.  This
 * structure specifically contains a single field representing a dynamic array
 * that should be used as the underlying data storage for the queue.
 *
 * You should not modify this structure.
 */
struct queue
{
  struct dynarray* array;
  void* head;
  int size;
  int queue_count;
};

/*
 * This function should allocate and initialize a new, empty queue and return
 * a pointer to it.
 */
struct queue* queue_create()
{
  struct queue* this_queue = malloc(sizeof(struct queue)); 
  this_queue->head = NULL;
  this_queue->size = 0;
  this_queue->array = dynarray_create();
  return this_queue;
}

/*
 * This function should free the memory associated with a queue.  While this
 * function should up all memory used in the queue itself, it should not free
 * any memory allocated to the pointer values stored in the queue.  This is the
 * responsibility of the caller.
 *
 * Params:
 *   queue - the queue to be destroyed.  May not be NULL.
 */
void queue_free(struct queue* queue)
{
  free(queue);
}

/*
 * This function should indicate whether a given queue is currently empty.
 * Specifically, it should return 1 if the specified queue is empty (i.e.
 * contains no elements) and 0 otherwise.
 *
 * Params:
 *   queue - the queue whose emptiness is being questioned.  May not be NULL.
 */
int queue_isempty(struct queue* queue)
{
  if(queue->size==0)
    return 1;
  else
    return -1;
}

/*
 * This function should enqueue a new value into a given queue.  The value to
 * be enqueued is specified as a void pointer.  This function must have O(1)
 * average runtime complexity.
 *
 * Params:
 *   queue - the queue into which a value is to be enqueued.  May not be NULL.
 *   val - the value to be enqueued.  Note that this parameter has type void*,
 *     which means that a pointer of any type can be passed.
 */
void queue_enqueue(struct queue* queue, void* val)
{
  dynarray_insert(queue->array,val);
  queue->size++;
  queue->head = val;
  // printf("[queue_enqueue]size=%d\n",queue->size);
  printf("[queue_enqueue]queue->head=%d\n",*(int *)(queue->head));
  // printf("[queue_enqueue]queue->head=%s\n",queue->head);
}

/*
 * This function should return the value stored at the front of a given queue
 * *without* removing that value.  This function must have O(1) average runtime
 * complexity.
 *
 * Params:
 *   queue - the queue from which to query the front value.  May not be NULL.
 */
void* queue_front(struct queue* queue)
{
  return queue->head;
}

/*
 * This function should dequeue a value from a given queue and return the
 * dequeued value.  This function must have O(1) average runtime complexity.
 *
 * Params:
 *   queue - the queue from which a value is to be dequeued.  May not be NULL.
 *
 * Return:
 *   This function should return the value that was dequeued.
 */
void* queue_dequeue(struct queue* queue)
{
  // printf("[queue_dequeue]queue->array->data[queue->size]=%d\n",*(int *)(queue->array->data[queue->size-1]));
  // printf("[queue_dequeue]queue->array->data[queue->size]=%s\n",queue->array->data[queue->size-1]);
  // printf("[queue_dequeue]queue->queue_count=%d\n",queue->queue_count);
  void* temp = queue->array->data[queue->size-1];
  queue->array->data[queue->size-1] = NULL;
  if(queue->size-2>=0)
  {
    queue->head = queue->array->data[queue->size-2];
    queue->size--;
  }
  else
  {
    printf("[queue_dequeue]no more data in queue\n");
    queue->head = NULL;
    queue->size--;
  }

  // queue->queue_count++;
  printf("[queue_dequeue]size=%d\n",queue->size);
  if(queue->head!=NULL)
    printf("[queue_dequeue]queue->head=%d\n",*(int *)(queue->head));
  return temp;
}

void queue_print(struct queue* queue)
{
  if(queue->size == 0)
  {
    printf("empty queue\n");
  }
  else
  {
    for(int i = queue->queue_count; i< queue->queue_count+queue->size;i++)
    {
      if(i%2 == 0)
      {
        printf("[%d]data = %d\n",i,*((int *)(queue->array->data[i])));
      }
      else
      {
        printf("[%d]data = %s\n",i,queue->array->data[i]);
      }
    }
  }
  printf("------\n");
}
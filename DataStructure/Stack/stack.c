/*
 * This file is where you should implement your stack.  It already contains
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
#include "stack.h"
#include "list.h"

/*
 * This is the structure that will be used to represent a stack.  This
 * structure specifically contains a single field representing a linked list
 * that should be used as the underlying data storage for the stack.
 *
 * You should not modify this structure.
 */
struct stack
{
  struct list* list;
  struct link* head;
  int size;
};

/*
 * This function should allocate and initialize a new, empty stack and return
 * a pointer to it.
 */
struct stack* stack_create()
{
  struct stack* this_stack = malloc(sizeof(struct stack)); 
  this_stack->head = NULL;
  this_stack->size = 0;
  this_stack->list = list_create();
  return this_stack;
}

/*
 * This function should free the memory associated with a stack.  While this
 * function should up all memory used in the stack itself, it should not free
 * any memory allocated to the pointer values stored in the stack.  This is the
 * responsibility of the caller.
 *
 * Params:
 *   stack - the stack to be destroyed.  May not be NULL.
 */
void stack_free(struct stack* stack)
{
    // list_free(stack->list);
    free(stack);
}

/*
 * This function should indicate whether a given stack is currently empty.
 * Specifically, it should return 1 if the specified stack is empty (i.e.
 * contains no elements) and 0 otherwise.
 *
 * Params:
 *   stack - the stack whose emptiness is being questioned.  May not be NULL.
 */
int stack_isempty(struct stack* stack)
{
  if(stack->size==0)
    return 1;
  else
    return -1;
}

/*
 * This function should push a new value onto a given stack.  The value to be
 * pushed is specified as a void pointer.  This function must have O(1)
 * average runtime complexity.
 *
 * Params:
 *   stack - the stack onto which a value is to be pushed.  May not be NULL.
 *   val - the value to be pushed.  Note that this parameter has type void*,
 *     which means that a pointer of any type can be passed.
 */
void stack_push(struct stack* stack, void* val)
{
  // printf("[stack_push]1\n");
  // printf("[stack_push]2:%d\n",*((int *)val));
  list_insert(stack->list,val);
  
  stack->size++;
  if(stack->head==NULL)
  {
    // printf("[stack_push]2\n");
    stack->head = stack->list->head;
    // stack->list->head->
  }
  else
  {
    // printf("[stack_push]3\n");
    stack->head = stack->head->next;
    // printf("[stack_push]4\n");
  }
  // printf("[stack_push]stack->head=%d\n",*((int *)stack->head->data));
  // printf("---\n");
}

/*
 * This function should return the value stored at the top of a given stack
 * *without* removing that value.  This function must have O(1) average runtime
 * complexity.
 *
 * Params:
 *   stack - the stack from which to query the top value.  May not be NULL.
 */
void* stack_top(struct stack* stack)
{
  return stack->head->data;
}

/*
 * This function should pop a value from a given stack and return the popped
 * value.  This function must have O(1) average runtime complexity.
 *
 * Params:
 *   stack - the stack from which a value is to be popped.  May not be NULL.
 *
 * Return:
 *   This function should return the value that was popped.
 */
void* stack_pop(struct stack* stack)
{
  void* data = stack->head->data;
  if(stack->size>0)
  {
    printf("[popped]=%d\n",*((int *)(data)));
    struct link* prev_link = stack->head->previous;
    list_remove_index(stack->list,stack->list->size-1);
    stack->head = prev_link;
    stack->size--;
  }
  else
  {
    // stack->head = NULL;
    printf("[stack_pop]empty stack\n");
  }
  // printf("[stack_pop]stack->head=%d\n",stack->head);
  // printf("[queue_dequeue]queue->head=%d\n",*(int *)(queue->head));
  // printf("[queue_dequeue]queue->head=%s\n",queue->head);
  return data;
}
void stack_print(struct stack* stack)
{
  // for(int i = 0; i< stack->size;i++)
  // {
  //   if(i%2 == 0)
  //   {
  //     printf("[%d]data = %d\n",i,*((int *)(stack->list->data[i])));
  //   }
  //   else
  //   {
  //     printf("[%d]data = %s\n",i,stack->list->data[i]);
  //   }
  // }
  struct list* _list = stack->list;
  printf("[List Info] size = %d:\n",_list->size);
  if(_list->size==0)
  {
      printf("[list info] _list = NULL\n");
      return;
  }
  struct link *temp_link = _list->head;
  int index = 0;
  while(temp_link->next!=NULL)
  {
      printf("[%d] %d\n",index,*((int *)temp_link->data));
      temp_link = temp_link->next;
      index++;
  }
    
  printf("------\n");
}
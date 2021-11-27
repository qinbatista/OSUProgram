/*
 * In this file, you will write the structures and functions needed to
 * implement a priority queue.  Feel free to implement any helper functions
 * you need in this file to implement a priority queue.  Make sure to add your
 * name and @oregonstate.edu email address below:
 *
 * Name: yupeng qin
 * Email:qinyu@oregonstate.edu
 */

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "pq.h"
#include "dynarray.h"

/*
 * This is the structure that represents a priority queue.  You must define
 * this struct to contain the data needed to implement a priority queue.
 */

struct pq
{
    struct dynarray* dataList;
    struct dynarray * priorityList;
};

/*
 * This function should allocate and initialize an empty priority queue and
 * return a pointer to it.
 */

struct pq* pq_create()
{
    struct pq* _pq = malloc(sizeof(struct pq));
    _pq->dataList = dynarray_create();
    _pq->priorityList = dynarray_create();
    return _pq;
}

/*
 * This function should free the memory allocated to a given priority queue.
 * Note that this function SHOULD NOT free the individual elements stored in
 * the priority queue.  That is the responsibility of the caller.
 *
 * Params:
 *   pq - the priority queue to be destroyed.  May not be NULL.
 */

void pq_free(struct pq* pq)
{
    assert(pq);
    free(pq->dataList);
    free(pq->priorityList);
    free(pq);
}

/*
 * This function should return 1 if the specified priority queue is empty and
 * 0 otherwise.
 *
 * Params:
 *   pq - the priority queue whose emptiness is to be checked.  May not be
 *     NULL.
 *
 * Return:
 *   Should return 1 if pq is empty and 0 otherwise.
 */

int pq_isempty(struct pq* pq)
{
    assert(pq);
    if(pq->dataList->size==0)
        return 1;
    else
        return 0;
}


/*
 * This function should insert a given element into a priority queue with a
 * specified priority value.  Note that in this implementation, LOWER priority
 * values are assigned to elements with HIGHER priority.  In other words, the
 * element in the priority queue with the LOWEST priority value should be the
 * FIRST one returned.
 *
 * Params:
 *   pq - the priority queue into which to insert an element.  May not be
 *     NULL.
 *   value - the value to be inserted into pq.
 *   priority - the priority value to be assigned to the newly-inserted
 *     element.  Note that in this implementation, LOWER priority values
 *     should correspond to elements with HIGHER priority.  In other words,
 *     the element in the priority queue with the LOWEST priority value should
 *     be the FIRST one returned.
 */

void pq_insert(struct pq* pq, void* value, int priority)
{
    assert(pq);
    void *p = malloc(sizeof(void));
    p = &priority;
    // new_priority = priority;
    // printf("pq->priorityList =%d\n",*(int *)p);
    dynarray_insert(pq->dataList,value);
    dynarray_insert(pq->priorityList,value);
    int count = pq->priorityList->size-1;
    // printf("inserted value:%d, capacity =%d\n", *(int *)value,pq->dataList->size);
    printf("max count:%d, inserted value = %d\n",count,*(int *)value);
    // printf("pq->priorityList =%d\n",*(int *)pq->priorityList->data[0]);
    // int up_count = 0;
    // up_count = count;
    while(count>0)
    {
        // printf("count-1 =%d\n",count-1);
        // printf("(count-1)/2 =%d\n",(count-1)/2);
        // printf("%d\n",*(int *)(pq->priorityList->data[(count-1)/2]));
        // printf("%d\n",*(int*)pq->priorityList->data[count-1]);
        printf("up [%d] =%d,down [%d] =%d\n",(count-1)/2,*(int *)(pq->dataList->data[(count-1)/2]),count,*(int*)pq->dataList->data[count]);
        if(*(int *)pq->priorityList->data[(count-1)/2]>*(int *)pq->priorityList->data[count])
        {
            void *temp = pq->dataList->data[count];
            pq->dataList->data[count] = pq->dataList->data[(count-1)/2];
            pq->dataList->data[(count-1)/2] = temp;

            void *temp1 = pq->priorityList->data[count];
            pq->priorityList->data[count] = pq->priorityList->data[(count-1)/2];
            pq->priorityList->data[(count-1)/2] = temp1;
            printf("swap: %d with %d \n",*(int *)pq->priorityList->data[count],*(int *)pq->priorityList->data[(count-1)/2]);
        }
        count = (count-1)/2;
        // if((count-1)/2==0 && count==1)
        // {
        //     if(*(int *)pq->priorityList->data[0]>*(int *)pq->priorityList->data[1])
        //     {
        //         void *temp = pq->dataList->data[0];
        //         pq->dataList->data[1] = pq->dataList->data[0];
        //         pq->dataList->data[0] = temp;

        //         void *temp1 = pq->priorityList->data[0];
        //         pq->priorityList->data[1] = pq->priorityList->data[0];
        //         pq->priorityList->data[0] = temp1;
        //         printf("swap: %d with %d \n",*(int *)pq->priorityList->data[1],*(int *)pq->priorityList->data[0]);
        //     }
        // }
    }
    
    for (int i = 0; i < pq->priorityList->size; i++)
    {
        printf("%d,", *(int *)pq->priorityList->data[i]);
    }
    printf("\n");
    printf("---------\n");
    
}


/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */

void* pq_first(struct pq* pq)
{
    assert(pq);
    return pq->dataList->data[pq->priorityList->size];
}

/*
 * This function should return the priority value of the first item in a
 * priority queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a priority value.  May not be
 *     NULL or empty.
 *
 * Return:
 *   Should return the priority value of the first item in pq, i.e. the item
 *   with LOWEST priority value.
 */

int pq_first_priority(struct pq* pq)
{
    assert(pq);
    return *(int *)pq->dataList->data[0];
}


/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value, and then remove that item
 * from the queue.
 *
 * Params:
 *   pq - the priority queue from which to remove a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */

void* pq_remove_first(struct pq* pq)
{
    assert(pq);
    pq->priorityList->data[0] = pq->priorityList->data[pq->priorityList->size-1];
    pq->dataList->data[0] = pq->dataList->data[pq->dataList->size-1];
    dynarray_remove(pq->priorityList,pq->priorityList->size-1);
    dynarray_remove(pq->dataList,pq->dataList->size-1);
    int count = 0;
    for (int i = 0; i < pq->priorityList->size; i++)
    {
        printf("%d,", *(int *)pq->priorityList->data[i]);
    }
    printf("\n");
    while(count < pq->priorityList->size)
    {
        // printf("%d <%d\n",count,pq->priorityList->size);
        // printf("%d <%d\n",2*count+2,pq->priorityList->size);
        // printf("count-1 =%d\n",count-1);
        // printf("(count-1)/2 =%d\n",(count-1)/2);
        // printf("%d\n",*(int *)(pq->priorityList->data[(count-1)/2]));
        // printf("%d\n",*(int*)pq->priorityList->data[count-1]);
        // printf("top[%d] =%d,",count,*(int *)(pq->dataList->data[count]));
        // printf("top right [%d] =%d,",2*count+1,*(int *)(pq->dataList->data[2*count+1]));
        // printf("top left [%d] =%d\n",2*count+2,*(int *)(pq->dataList->data[2*count+2]));
        // printf("a\n");
        if(2*count+1>pq->priorityList->size || 2*count+2>pq->priorityList->size)
            break;
        // if(2*count+2>pq->priorityList->size)
        //     break;
        // if(*(int *)pq->dataList->data[count]>*(int *)pq->priorityList->data[2*count+1] || *(int *)pq->dataList->data[count]> *(int *)pq->priorityList->data[2*count+2])
        // {
        if(*(int *)pq->priorityList->data[2*count+1] < *(int *)pq->priorityList->data[2*count+2])
        {
            if(*(int *)pq->dataList->data[count]<*(int *)pq->priorityList->data[2*count+1])
                break;
            void *temp = pq->dataList->data[count];
            pq->dataList->data[count] = pq->dataList->data[2*count+1];
            pq->dataList->data[2*count+1] = temp;

            void *temp1 = pq->priorityList->data[count];
            pq->priorityList->data[count] = pq->priorityList->data[2*count+1];
            pq->priorityList->data[2*count+1] = temp1;
            printf("count = %d, swap count = %d,  swap left: %d with %d \n", count,2*count+1,*(int *)pq->priorityList->data[count],*(int *)pq->priorityList->data[2*count+1]);
            count = 2*count+1;
        }
        else
        {
            if(*(int *)pq->dataList->data[count]<*(int *)pq->priorityList->data[2*count+2])
                break;
            void *temp = pq->dataList->data[count];
            pq->dataList->data[count] = pq->dataList->data[2*count+2];
            pq->dataList->data[2*count+2] = temp;

            void *temp1 = pq->priorityList->data[count];
            pq->priorityList->data[count] = pq->priorityList->data[2*count+2];
            pq->priorityList->data[2*count+2] = temp1;
            printf("count = %d, swap count = %d,  swap right: %d with %d \n", count,2*count+2,*(int *)pq->priorityList->data[count],*(int *)pq->priorityList->data[2*count+2]);
            count = 2*count+2;
        }
        // }
        // printf("aaaa\n");
    }
    for (int i = 0; i < pq->priorityList->size; i++)
    {
        printf("%d,", *(int *)pq->priorityList->data[i]);
    }
    printf("\n");
    printf("---------max count = %d\n",pq->priorityList->size-1);
    return pq->priorityList->data[0];
}


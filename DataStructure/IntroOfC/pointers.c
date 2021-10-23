// gcc --std=c99 -o out pointers.c  
// ./out
#include<stdio.h>
#include <stdlib.h> 
struct pokeman
{
    char* name;
    int dex_num;
};
void inception(void *a, void (*fp)(void*));
void printInt(void *x);
int compare_int(void* a, void* b);

void inception(void *a, void (*fp)(void*))
{
    fp(a);
    printf("a");
}

void printInt(void *x)
{
    int* x_int = x;
    printf("passed1 %d\n", *x_int);
    printf("passed2 %d\n", *(int*)x);
}

void sort_duo(void* a1, void* b1, int (*compare)(void* a, void* b))
{
    if(!(compare(a1,b1)))
    {
        void* temp = a1;
        a1 = b1;
        b1 = temp;
    }
}

int compare_int(void* a, void* b)
{
    int* a_int = a;
    int* b_int = b;
    return  (*(int*)a)<(*b_int);
}

int main()
{
    void (*funk)(void*);
    int a = 10;
    funk = &printInt;
    funk(&a);
    inception(&a,funk);
    
    return 0;
}
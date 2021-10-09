// gcc --std=c99 -o out main.c  
// ./out
#include<stdio.h>
#include <stdlib.h> 
struct pokemon
{
    char* name;
    int dex_num;
};
void printwhatipass(int x);
void printwhatipass(int x)
{
    printf("passed %d\n", x);
}
int main()
{
    int a = 5;
    char* b = "aaaa";
    float pi = 3.1444444;
    printf("Int a = %d\n", a);
    printf("String b = %s\n", b);
    printf("Float f = %f\n", pi);
    printf("1: %d\n2: %s\n3: %4.3f\n", a, b, pi);
    printf("hello world\n");

    if(5!=6)
    {
        printf("True!\n");
    }
    else if(5!=6)
    {

    }
    else
    {

    }
    for(int i = 0; i<5; i++)
    {
        printf("i = %d\n", i);
    }
    // while (1)
    // {
    //     /* code */
    // }
    printwhatipass(20);
    struct pokemon pika = {.name = "Sparky", .dex_num = 25};

    pika.name = "Bolt";
    printf("Pokemon's name: %s\n", pika.name);
    int t = 20;
    int* t_ptr = &t;

    printf("Pointer address: %p\n", t_ptr);
    printf("Pointer value: %d\n", *t_ptr);

    *t_ptr = 10;
    void* v_ptr = t_ptr;
    void* v_ptr1 = &t; 
    printf("%d\n", *((int* )(v_ptr)));
    printf("%d\n", *((int* )(v_ptr1)));
    void* v_ptr2 = &pika;
    printf("%s\n", ((struct pokemon*)v_ptr2)->name);

    struct pokemon* bulba = malloc(10 * sizeof(struct pokemon));
    bulba[0].name = "follwer0";
    bulba[1].name = "follwer1";
    bulba->name = "follwer2";
    printf("->%s\n",bulba->name);
    printf("0=%s\n",bulba[0].name);
    printf("1=%s\n",bulba[1].name);
    printf("2=%s\n",bulba[2].name);
    free(bulba);
    return 0;
}

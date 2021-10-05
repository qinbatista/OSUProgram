#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int main() 
{
    char *a = "this is a string";
    char b[] = "this is also a string";
    char *c = malloc(128*sizeof(char));
    c = strncpy(c, a, 128);
    int len = strlen(c);

    char* d = malloc((len+1)*sizeof(char));
    d = strncpy(d,c,(len+1));

    snprintf(c, 128, "%s \t %d \t %f", "hello", 22, 2.3);

    c[2] = 'u';
    // a[2] = 'u';
    b[2] = 'u';
    printf("a: %s\n", a);
    printf("b: %s\n", b);
    printf("c: %s\n", c);
    printf("d: %s\n", d);
    printf("len:%d\n", len);
    free(c);
    free(d);
    return 0;
}
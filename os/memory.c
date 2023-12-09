#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int *p = (int*) malloc(10*sizeof(int));
    printf("%lu\n", sizeof(p));
    int x[10];
    printf("%lu\n", sizeof(x));
    free(p);
    free(p);

    char* src = "hello";
    char* dst = (char*)malloc(strlen(src)+1);
    strcpy(dst, src);
    printf("%s\n", dst);

    int *y = (int*)malloc(sizeof(int));
    printf("%d\n", *y);
    return 0;
}

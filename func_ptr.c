#include<stdio.h>
/* Declare a function pointer type */
typedef int (*FuncPtr)(int, int);

/* Define a function to add two numbers */
int add(int a, int b) {
    return a+b;
}

int main()
{
    /* Create a function pointer */
    FuncPtr ptr = &add;
    /* Using the function pointer to call the function */
    int result = ptr(10, 20);
    /* Function pointer in c example */
    printf(" Adding two number :%d",result);
    return 0;
}
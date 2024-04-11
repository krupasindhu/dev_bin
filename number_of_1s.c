#include<stdio.h>
/* Count the set bits */
unsigned int countSetBits(unsigned int n)
{
    unsigned int count = 0;
    while (n != 0) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

/* Program to test function countSetBits */
int main()
{
    int i = 6;
    printf("%d", countSetBits(i));
    return 0;
}

#include <stdio.h>
/*  C Program to swap bits in a given number
 * Input:
 * x = 28 (11100)
 * p1 = 0 (Start from first bit from right side)
 * p2 = 3 (Start from 4th bit from right side)
 * n = 2 (No of bits to be swapped)
 * Output:
 * 7 (00111)
 * The 2 bits starting from 0th position (from right side) are
 * swapped with 2 bits starting from 4th position (from right side)
*/
void print_bits(unsigned int num) {
    int arr[32];
    for(int i = 0; i < 32; i++) {
        if(num & (1 << i)) {
            arr[i] = 1;
        } else {
            arr[i] = 0;
        }
    }
    for (int i = 31; i>=0; --i) {
        printf("%d", arr[i]);
    }
    printf("\n");
}
int swapBits(unsigned int x, unsigned int p1, unsigned int p2, unsigned int n)
{
    /* Move all bits of first set to rightmost side */
    print_bits(x);
    unsigned int set1 = (x >> p1) & ((1U << n) - 1);
    print_bits(set1);
 
    /* Move all bits of second set to rightmost side */
    unsigned int set2 = (x >> p2) & ((1U << n) - 1);
    print_bits(set2);
    /* XOR the two sets */
    unsigned int xor = (set1 ^ set2);
    print_bits(xor);
    /* Put the xor bits back to their original positions */
    xor = (xor << p1) | (xor << p2);
    print_bits(xor);
    /* XOR the 'xor' with the original number so that the 
       two sets are swapped */
    unsigned int result = x ^ xor;
    print_bits(result);
    return result;
}
 
/* Driver program to test above function*/
int main()
{
    int res = swapBits(28, 0, 3, 2);
    printf("\nResult = %d ", res);
    return 0;
}
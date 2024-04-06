#include<stdio.h>
/*
 * given arr = [6,2,3,4,7,2,1,7,1] k = 4
 * pickup four cards in any possible away either from left and right
 * but it should be consumative.
 * Task is to maximize the points which we have pickedup
 *
 */
int max(int a , int b){
    return (a>b)?a:b;
}
int maximum_point_obtained_from_card(int arr[], int n, int k)
{
    int lsum = 0, rsum = 0, maxsum = 0;
    for(int i=0; i<k; i++) {
        lsum = lsum + arr[i];

        
    }
    /* assuming we have added all four now to lsum */
    int rindex = n-1;
    /* sinking the left */
    for(int i = k-1; i>=0; --i) {
        lsum = lsum - arr[i];
        rsum = rsum + arr[rindex];
        rindex = rindex - 1;
        maxsum = max(maxsum, lsum+rsum);
    }
    return maxsum;
}
int main()
{
    printf("START CODE ........\n");

    int arr[] = {6,2,3,4,7,2,1,7,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    for(int i =0; i<size; i++) {
        printf(" %d\t",arr[i]);
    }
    int result = maximum_point_obtained_from_card(arr, size, k);
    printf("RESULT :%d", result);
    if(result == 16) {
        printf("Test case 1: PASS \n");
    } else {
        printf("Test case 1: FAILED \n");
    }
    return 0;
}
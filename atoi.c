#include<stdio.h>

int myAtoi(char *str);

int myAtoi(char* str)
{
    /* intialize the result */
    int res = 0;
    /* 
     * Iterate through all characters
     * of input string and update result
     * take ASCII character of corresponding digit and
     * subtract the code from '0' to get numerical
     * value and multiply res by 10 to shuffle
     * digits left to update running total
     */
     for(int i = 0; str[i] != '\0'; ++i) {
        res = res * 10 + str[i] - '0';
     }

    return res;
}

int main()
{
    char str[] = "123456";
    /* function call */
    int val = myAtoi(str);
    printf("Val :%d\n", val);
}
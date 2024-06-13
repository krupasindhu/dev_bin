#include<iostream>
#include<vector>
using namespace std;

int fib(int n, vector<int> &dp) {
    if(n <= 1 ) return n; // base case
    // check before computaion
    if(dp[n] != -1) return dp[n];
    // store the result to dp
    return dp[n] = fib(n-1, dp) + fib(n-2, dp);
}
int main() {
    // Fibonacci number n = 5
    int n = 5;
    // create a dp vector of n+1
    vector<int> dp(n+1, -1);
    cout << fib(n, dp); 
    return 0;
}
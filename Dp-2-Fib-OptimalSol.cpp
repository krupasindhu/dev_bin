#include<iostream>
#include<vector>
using namespace std;

// convert it to tabulation format
int main() {
    // Fibonacci number n = 5
    int n = 9;
    int prev2 = 0;
    int prev1 = 1;
    int curr = 0;
    for (int i = 2; i <= n; i++) {
       curr = prev1 + prev2;
       prev2 = prev1;
       prev1 = curr;
    }
    cout << prev1;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
///
/// @Sub: findout the length of longest substring
/// @params [in]: string
/// @retun type:int (length of longest substring)
///
int lengthofLongestSubstring(string s) {
    vector<int> mpp(256, -1);
    int left = 0, right = 0;
    int n = s.size();
    int len = 0;
    while(right < n) {
        // char found in map
        if (mpp[s[right]] != -1) {
            left = max(mpp[s[right]] + 1, left);
        }
        mpp[s[right]] = right;
        len = max(len, right - left + 1);
        right++;
    }
    return len;
}

int main()
{
    string str = "cadbzabcd";
    //cout<< "The length of the longest substring without repeating characters is:" <<lengthofLongestSubstring(str);
    return 0;
}


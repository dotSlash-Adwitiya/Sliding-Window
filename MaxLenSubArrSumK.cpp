#include<bits/stdc++.h>
using namespace std;

// * Initially take size of window = 1
// * Two operations: Expand & Shrink
/*
  * Expansion happens with right ptr (Increase the window size)
  * Shrinkage happens with left ptr (Decrease the window size)
*/

int longestSubArrLenK(int *arr, int n, int k) {
  int left = 0, right = 0, currSum = 0, maxLen = 0;

  while(right < n) {
    currSum += arr[right];

    if(currSum > k){
    //  * Shrink till sum becomes <= K
      while(currSum > k){
        currSum -= arr[left];
        left++;
      }
    }

    if(currSum <= k) 
      maxLen = max(maxLen, right - left + 1);
    
    //  * Expand
    right++;
  }
  return maxLen;
}

int main()
{
  int arr[] = {2,5,1,10,10};
  cout << longestSubArrLenK(arr, sizeof(arr)/sizeof(arr[0]), 14) << endl;
  return 0;
}
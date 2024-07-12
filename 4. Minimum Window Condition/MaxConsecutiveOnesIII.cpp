#include<bits/stdc++.h>
using namespace std;

// * Brute Force will be: Generate all subarrays and get the maximum subarray with 0s <= K

// * Better Approach - O(2N) - T.C
int longestOnes(vector<int>& nums, int k) {
    int len = 0, maxLen = 0, n = nums.size(), zeroes = 0;

    for(int right = 0, left = 0; right < n; right++){
        if(nums[right] == 0) zeroes++;
        if(zeroes > k){
            while(zeroes > k){
                if(nums[left] == 0) zeroes--;
                left++;
            }
        }
        if(zeroes <= k) maxLen = max(maxLen,right - left + 1);
    }
    return maxLen;
}
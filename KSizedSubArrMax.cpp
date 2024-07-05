#include<bits/stdc++.h>
using namespace std;

// * BRUTE FORCE: T.C: O(N*K), SC: O(1)
vector <int> max_of_subarrays(int *arr, int n, int k)
{
  vector <int> ans;
  for(int i = 0; i <= n-k; i++) {
      int maxEle = -1;
      for(int j = i, cnt = 0; cnt < k; j++, cnt++) {
          maxEle = max(maxEle, arr[j]);
      }
      ans.push_back(maxEle);
  }
  return ans;
}

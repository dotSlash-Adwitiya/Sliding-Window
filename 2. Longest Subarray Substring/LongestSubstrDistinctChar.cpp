#include<bits/stdc++.h>
using namespace std;

// * T.C : O(N² * i*j) - near about O(n²)
bool check(int i, int j, string s) {
  for(int k = i; k < j; k++){
      if(s[k] == s[j])
          return false;
  }
  return true;
}
int lengthOfLongestSubstring(string s) {
  if(s == "")
      return 0;

  int n = s.size(), maxLen = 0;
  
  for(int i = 0; i < n-1; i++) {
      string sub = "";
      for(int j = i; j < n; j++){
          bool flag = check(i, j, s); //  * Check in range - i to j, if the current character is repeated
          if(flag)
              sub += s[j];
          else break;  
      }
      maxLen = max(maxLen, (int)sub.size());
  }
  
  return (maxLen == 0 ? 1 : maxLen);
}

// * Better Approach using SET:
// * T.C : O(nlogn) for inserting and deleting from SET
// * S.C: O(N) where N = no of characters in the string
int lengthOfLongestSubstring(string s) {
  unordered_set<char> st;
  int i = 0, j = 0, maxLen = 0;
  
  while(j < s.size()) {
      char ch = s[j];
      if(st.find(ch) != st.end()){
          maxLen = max(maxLen, j-1-i+1);
          while(i < j && s[i] != ch){
              st.erase(st.find(s[i])); // * Shring the window and remove characters
              i++;
          }
          if(i < j) {
              st.erase(st.find(s[i])); // * Erase the previous occurcence of this character
              i++;
          }
      }
      st.insert(ch);
      j++;
  }
  maxLen = max(maxLen, j-1-i+1);
  return maxLen;
}

// * Optimal Approach by using INDEXES and a 256 Size arr[]
//  * T.C: O(N), S.C: O(256)
int lengthOfLongestSubstring(string s) {
  int n = s.size(), maxLen = 0, left = 0, right = 0;
  vector<int> hash(256, -1);
  
  while(right < n) {
      if(hash[s[right]] != -1){
          // * Ensure current character's previous occurence 
          // * is in the range of current window. If it is, then update the left Pointer to + 1 of it.
          // * Else we don't need to move the left pointer!!
          if(hash[s[right]] >= left) 
              left = hash[s[right]]+1;
      }
      hash[s[right]] = right;
      maxLen = max(maxLen, right - left + 1);
      right++;
  }
  return maxLen;
}
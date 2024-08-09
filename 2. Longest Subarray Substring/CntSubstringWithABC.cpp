#include<bits/stdc++.h>
using namespace std;

// * BRUTE FORCE
int numberOfSubstrings(string s) {
  int cnt = 0;
  for(int i = 0; i < s.size(); i++) {
      bool a = 0, b = 0, c = 0;
      for(int j = i; j < s.size(); j++) {
          if(s[j] == 'a')
              a = 1;
          if(s[j] == 'b')
              b = 1;
          if(s[j] == 'c')
              c = 1;
          if( a && b && c )    
              cnt++;
      }
  }
  return cnt;
}

// * OPTIMAL SOLUTION
int numberOfSubstrings(string s) {
    int count[3] = {0, 0, 0},res = 0 , left = 0, n = s.length();
    for (int right = 0; right < n; right++) {
        ++count[s[right] - 'a'];
        while (count[0] && count[1] && count[2])
            --count[s[left++] - 'a'];
        res += left;
    }
    return res;
}
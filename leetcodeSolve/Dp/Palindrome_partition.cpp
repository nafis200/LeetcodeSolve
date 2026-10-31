

#include <bits/stdc++.h>
using namespace std;

// Time o(n^3) Space o(1)

string t;
int nums;
// bool palindrome(int l, int r){
//     while(l <= r && t[l] == t[r]){
//         l++;
//         r--;
//     }
//     return l > r;
// }

// int countSubstrings(string s) {
//       t = s;
//       int n = s.size();  
//       int nums = 0;
//       for(int i = 0; i < n; i++){
//          for(int j = i; j < n; j++){
//             if(palindrome(i, j)){
//                 nums++;
//             }
//          }
//       }                
//       return nums;
// }


int countSubstrings(string s) {
      t = s;
      int n = s.size();  
      int nums = 0;
    // Odd
    for(int center = 0; center < n; center++){
         int l = center;
         int r = center;
         while(l >= 0 && r < n && s[l] == s[r]){
             nums++;
             l--;
             r++;
         }
    }

    // even

    for(int center = 1; center < n; center++){
        int l = center - 1;
        int r = center;
         while(l >= 0 && r < n && s[l] == s[r]){
             nums++;
             l--;
             r++;
         }
    }
    return nums;
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "aab";
  int result = countSubstrings(s);
  cout << result << "\n";
}
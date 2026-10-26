// 0 - 3 months:
// Microsoft (3) — TCS (2) — LinkedIn (2)

// 0 - 6 months:
// Amazon (3) — Google (2) — Infosys (2)

// 6 months ago:
// Meta (7) — Bloomberg (4) — Goldman Sachs (2) — Zoho (2) — Uber (2) — Accenture (2) — Nutanix (2) — MAQ Software (2)

// Problem_Link: https://leetcode.com/problems/longest-palindromic-subsequence/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>memo;

 int dp(int i, int j, string &s){
     if(i == j){
        return 1;
     } 
     if(i > j){
        return 0;
     }
     if(memo[i][j] != -1){
         return memo[i][j];
     }
     int ans = 0;
     if(s[i] == s[j]){
        ans = max(ans, dp(i + 1, j - 1 ,s) + 2);
     }
     else{
          ans = max(ans, dp(i + 1, j, s));
          ans = max(ans, dp(i, j - 1, s));
     }
     
         
     
     return memo[i][j] = ans;
 }  

 int longestPalindromeSubseq(string s) {
      int n = s.size();
      memo.assign(n + 1, vector<int>(n + 1, -1));
      return dp(0, n - 1, s);
 }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "bbbab";
    int ans = longestPalindromeSubseq(s);
    cout << ans << "\n";

}
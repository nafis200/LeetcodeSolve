// 0 - 3 months:
// Google (16) — TikTok (11) — Microsoft (5) — Yandex (2) — PayPal (2) —
// Salesforce (2)

// 0 - 6 months:
// Amazon (7) — Walmart Labs (4) — Oracle (3) — Bloomberg (2) — Splunk (2) —
// Flexport (2)

// 6 months ago:
// Apple (11) — Goldman Sachs (11) — Adobe (10) — Uber (9) — Meta (8) —
// Atlassian (6) — Commvault (5) — Intuit (4) — Accenture (4) — IBM (3)

// problem_Link:
// https://leetcode.com/problems/longest-increasing-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

// time o(n ^ 2 ) space o(n ^ 2)

// int n;
// vector<vector<int>>memo;

//  int dp(vector<int>& nums, int i, int prev){
//        if(i == n){
//           return 0;
//        }
//        if(memo[i][prev] != -1){
//           return memo[i][prev];
//        }
//        int ans = dp(nums, i + 1, prev);
//        if(prev == -1 || nums[i] > nums[prev]){
//           ans = max(ans, dp(nums, i + 1, i) + 1);
//        }
//        return memo[i][prev + 1] = ans;
//  }

//   int lengthOfLIS(vector<int>& nums) {
//        n = nums.size();
//        memo.assign(n + 1, vector<int>(n + 1, -1));
//        return dp(nums, 0, -1); 
//   }

int lengthOfLIS(vector<int>& nums) {
       set<int>st;
       int n = nums.size();
       for(int i = 0; i < n; i++){
           int num = nums[i];
           auto it = lower_bound(st.begin(),st.end(), num);
           if(it != st.end()){
               st.erase(it);
           }
           st.insert(num);
       }
       return st.size();
  }




int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {0, 1, 0, 3, 2, 3};
  int ans = lengthOfLIS(nums);
  cout << ans << "\n";
}
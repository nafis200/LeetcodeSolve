

#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<vector<int>>> memo;

int dp(vector<int>&nums, int i, int first, int last) {
      if(i == n){
        return 0;
      }
      if(memo[i][first][last] != -1){
        return memo[i][first][last];
      }
      int ans = dp(nums, i + 1, first, 0);
      if(last == 0){
          if(i == n - 1 && first == 0){
             ans = max(ans, dp(nums, i + 1, first, 1) + nums[i]);
          }
          else if(i != n - 1){
              ans = max(ans, dp(nums, i + 1, first, 1) + nums[i]);
          }
      }
      return memo[i][first][last] = ans;
}

int rob(vector<int>& nums) {
    n = nums.size();
    memo.assign(n, vector<vector<int>>(2, vector<int>(2, -1)));
    int ans = 0;
    ans = dp(nums, 1, 1, 1) + nums[0];
    ans = max(ans, dp(nums, 1, 0, 0));
    return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {2, 3, 2};
  int ans = rob(nums);
  cout << ans << "\n";
}
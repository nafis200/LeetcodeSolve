

#include <bits/stdc++.h>
using namespace std;

vector<int> memo;

int dp(vector<int>& nums, int target) {
  if (target == 0) {
    return 1;
  }
  if (target < 0) {
    return 0;
  }
  if(memo[target] != -1){
     return memo[target];
  }
  int ans = 0;
  for(int i = 0; i < nums.size(); i++){
      if(target - nums[i] >= 0){
           ans += dp(nums, target - nums[i]);
      }
  }
  return memo[target] = ans;
}

int combinationSum4(vector<int>& nums, int target) {
  int n = nums.size();
  memo.assign(target + 1, -1);
  int ans = dp(nums, target);
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {1, 2, 3};
  int target = 4;
  int ans = combinationSum4(nums, target);
  cout << ans << "\n";
}
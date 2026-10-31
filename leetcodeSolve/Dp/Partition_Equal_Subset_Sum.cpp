

#include <bits/stdc++.h>
using namespace std;
int n;

vector<vector<int>>memo;

bool dp(int i, int target,vector<int>& nums){
     if(i == n){
        if(target == 0){
            return true;
        }
        return false;
     }
      if(target < 0){
        return false;
     }
     if(memo[i][target] != -1){
        return memo[i][target];
     }
    

     return memo[i][target] = dp(i + 1, target, nums) || dp(i + 1, target - nums[i], nums);
}


bool canPartition(vector<int>& nums) {
     int sum = 0;
     n = nums.size();
     for(auto i : nums){
         sum += i;
     } 
     if(sum % 2){
        return false;
     }
     memo.assign(n + 1, vector<int>(sum + 1, -1));
     return dp(0, sum / 2, nums);

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {1, 5, 11, 5};
  bool ans = canPartition(nums);
  cout << ans << "\n";
}
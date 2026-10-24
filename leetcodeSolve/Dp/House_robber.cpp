

#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>>memo;

int dp(vector<int>& nums, int i, int prev){
    if(i == n){
        return 0;
    }
    if(memo[i][prev] != -1){
        return memo[i][prev];
    }
    int ans = 0;
    ans = dp(nums, i + 1, 0);
    if(prev == 0){
        ans = max(ans, dp(nums, i + 1, 1) + nums[i]);
    }
   
    return memo[i][prev] = ans;
}

int rob(vector<int>& nums) {
    n = nums.size();
    memo.assign(n + 1, vector<int>(2, -1));
    return dp(nums, 0, 0);
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {2,1,1,2};
    int ans = rob(nums);
    cout << ans << " ";
}

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> memo;
vector<int> a;
int dp(int l, int r) {
     if(l == r - 1){
        return 0;
     }
     if(memo[l][r] != -1){
        return memo[l][r];
     }
     int ans = 0;
     for(int k = l + 1; k < r; k++){
        int left = dp(l, k);
        int right = dp(k, r);
        int gain = a[k] * a[l] * a[r];
        ans = max(ans,left + right + gain);
     }
     return memo[l][r] = ans;
}

int maxCoins(vector<int>& nums) {
   a.push_back(1);
   for(auto i : nums){
      a.push_back(i);
   } 
   a.push_back(1);
   int n = a.size();
   memo.assign(n, vector<int>(n, -1));

   return dp(0, n - 1);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {3, 1, 5, 8};
  int ans = maxCoins(nums);
  cout << ans << "\n";
}
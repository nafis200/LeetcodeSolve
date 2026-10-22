#include <bits/stdc++.h>
using namespace std;


int n;

vector<vector<int>> memo;

int dp(int i,int amount, vector<int>& coins) {
     if(i == n){
        if(amount == 0){
            return 1;
        }
        return 0;
     }
     if(i > n || amount < 0){
         return 0;
     }
     if(memo[i][amount] != -1){
        return memo[i][amount];
     }
     int ans = 0;
     ans = dp(i + 1, amount, coins);
     if(amount - coins[i] >= 0)
     ans += dp(i, amount - coins[i], coins);
     return memo[i][amount] = ans;
}




int change(int amount, vector<int>& coins) {
  n = coins.size();
  memo.assign(n + 1, vector<int>(amount + 1, -1));
  int ans = dp(0, amount, coins);
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int amount = 5;
  vector<int> coins = {1, 2, 5};
  int ans = change(amount, coins);
  cout << ans << "\n";
}
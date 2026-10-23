

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int>memo;
int dp(int i, string &s){
    if(i == n){
        return 1;
    }
    if(s[i] == '0'){
        return 0;
    }
    if(memo[i] != -1){
        return memo[i];
    }
    int ways = dp(i + 1, s);
    if(i + 1 < n){
        int nums = (s[i] - '0') * 10 + (s[i + 1] - '0');
        if(nums >= 0 && nums <= 26){
            ways += dp(i + 2, s);
        }
    }
    return memo[i] = ways;
}
int numDecodings(string s) {
    n = s.size();
    memo.assign(n + 1, -1);
    return dp(0, s);

}



int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "226";
  int ans = numDecodings(s);
  cout << ans << "\n";
}
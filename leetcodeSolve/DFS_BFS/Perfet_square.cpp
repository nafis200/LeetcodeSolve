
#include<bits/stdc++.h>
using namespace std;
int numSquares(int n) {
    vector<int>dp(n + 1, 1e9);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j * j <= i; j++){
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp[n];
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 12;
    cout << numSquares(n) << "\n";
}
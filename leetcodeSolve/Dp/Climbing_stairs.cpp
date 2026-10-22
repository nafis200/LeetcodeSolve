

    #include<bits/stdc++.h>
    using namespace std;
    vector<int>dp;

    // int f(int n){
    //     if(n == 0){
    //         return 1;
    //     }
    //     if(n < 0){
    //         return 0;
    //     }
    //     if(dp[n] != -1){
    //         return dp[n];
    //     }
    //     int ans = f(n - 1) + f(n - 2);
    //     return dp[n] = ans;
    // }

    int climbStairs(int n) {
        dp.assign(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }


   

  

    int32_t main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = 3;
        int ans = climbStairs(n);
        cout << ans << "\n";
    }
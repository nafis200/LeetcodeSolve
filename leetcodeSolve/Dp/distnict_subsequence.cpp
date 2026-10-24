

#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>>memo;



int dp(int i, int j, string &s, string &t){
    if(i == n){
        if(j == m){
            return 1;
        }
        return 0;
    }

    if(j == m){
        return 1;
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    int ans = 0;
    if(s[i] == t[j]){
        ans = ans + dp(i + 1, j + 1, s, t) + dp(i + 1, j, s, t);
    }
    else{
        ans += dp(i + 1, j, s, t);
    }
    return memo[i][j] = ans;

}


 int numDistinct(string s, string t) {
     n = s.size();
     m = t.size();
     memo.assign(n + 1, vector<int>(m + 1, -1));
     return dp(0, 0, s, t);
 }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "rabbbit", t = "rabbit";
    int ans = numDistinct(s, t);
    cout << ans << "\n";
}
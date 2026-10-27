
#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int ans = 0;
    int mx = prices[n - 1];
    int mn = prices[n - 1];
    for(int i = n - 2; i >= 0; i--){
        if(prices[i] > mx){
            mx = prices[i];
            mn = prices[i];
        }
        else{
            mn = prices[i];
        }
        ans = max(ans, mx - mn);
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>prices = {7,6,4,3,1};

    cout << maxProfit(prices) << "\n";
}
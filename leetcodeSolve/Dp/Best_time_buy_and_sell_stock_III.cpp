
#include<bits/stdc++.h>
using namespace std;
// int maxProfit(vector<int>& prices) {
//    int n = prices.size();
   
//    int buy = INT_MIN;
//    int sell = 0;
//    int buy1 = INT_MIN;
//    int sell1 = 0;
//    for(int i = 0; i < n; i++){
//        int p = prices[i];
//        buy = max(buy, -p);
//        sell = max(sell, buy + p);
//        buy1 = max(buy1, sell - p);
//        sell1 = max(sell1, buy1 + p);
//    }
//    return sell1;
// }


int maxProfit(vector<int>& prices) {
   int n = prices.size();
   vector<int>sell(n + 1, 0);
   vector<int>buy(n + 1, INT_MIN);

   buy[1] = 0;
   for(int i = 0; i < n; i++){
      int p = prices[i];
      for(int k = 1; k <= 2; k++){
           buy[k] = max(buy[k], sell[k - 1] - p);
           sell[k] = max(sell[k], buy[k] + p);
      }
   }
   return sell[2];
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>prices = {3,3,5,0,0,3,1,4};
    cout << maxProfit(prices) << "\n";
}
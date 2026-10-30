// 0 - 3 months:
// Airbnb (3) — Snowflake (2) — DoorDash (2) — Verkada (2)

// 0 - 6 months:
// Google (4) — Oracle (4) — Amazon (3) — Infosys (2) — Uber (2) — Meesho (2)

// 6 months ago:
// Pinterest (19) — Bloomberg (11) — Microsoft (9) — Goldman Sachs (6) — Meta
// (4) — PhonePe (4) — WeRide (4) — Flipkart (2) — ByteDance (2) — TikTok (2)

// Problem_Link: https://leetcode.com/problems/maximum-profit-in-job-scheduling/

#include <bits/stdc++.h>
using namespace std;


class cmp{
    public:
     bool operator()(pair<pair<int,int>,int>&a,pair<pair<int,int>,int>&b){
         if(a.first.second < b.first.second){
            return true;
         }
         return false;
     }
};


int jobScheduling(vector<int>& startTime, vector<int>& endTime,vector<int>& profit) {
   int n = profit.size();
   vector<pair<pair<int,int>,int>>maxProfit(n);
   for(int i = 0; i < n; i++){
       maxProfit[i].first.first = startTime[i];
       maxProfit[i].first.second = endTime[i];
       maxProfit[i].second = profit[i];
   }    
   sort(maxProfit.begin(),maxProfit.end(),cmp());
   
   int mxProfit = 0;
   vector<int>dp(n, 0);
   vector<int>pref(n + 1, 0);
   // for(int i = 0; i < n; i++){
   //       dp[i] = maxProfit[i].second;
   //       for(int j = i - 1; j >= 0; j--){
   //          if(maxProfit[i].first.first >= maxProfit[j].first.second){
   //              dp[i] = max(dp[i], dp[j] + maxProfit[i].second);
   //          }
   //       }
   // }
   
   pref[0] = maxProfit[0].second;
   dp[0] = maxProfit[0].second;
   for(int i = 1; i < n; i++){
       dp[i] = maxProfit[i].second;
       int l = 0, r = i - 1;
       int ans = -1;
       while(l <= r){
           int mid = (l + r) / 2;
           if(maxProfit[mid].first.second <= maxProfit[i].first.first){
               l = mid + 1;
               ans = mid;
           }
           else{
              r = mid - 1;
           }
       }
       if(ans != -1){
          dp[i] = max(dp[i], dp[i] + pref[ans]);
       }
       pref[i] = max(dp[i], pref[i - 1]);
       
   }

   int ans = -1e9;
   for(int i = 0; i < n; i++){
      ans = max(ans, dp[i]);
   }
   return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> startTime = {1, 2, 3, 3};
  vector<int> endTime =   {3, 4, 5, 6};
  vector<int> profit = {50, 10, 40, 70};
  int ans = jobScheduling(startTime, endTime, profit);
  cout << ans << "\n";
}
// 0 - 3 months:
// Pinterest (6)

// 0 - 6 months:
// Salesforce (3) — Walmart Labs (2)

// 6 months ago:
// Amazon (18) — Google (14) — Netflix (11) — Meta (8) — Yandex (7) — Uber (5) —
// Booking.com (4) — Bloomberg (3) — Flipkart (3) — Citadel (3)

// problem_Link: https://leetcode.com/problems/reconstruct-itinerary/

#include <bits/stdc++.h>
using namespace std;

// O(V + E log E)
// space o(E)

unordered_map<
    string,
    priority_queue<string, vector<string>, greater<string>>
> g;

    vector<string>ans;

void DFS(string src){
    auto &pq = g[src];
    while(!pq.empty()){
        string x = pq.top();
        pq.pop();
        DFS(x);
    }
    ans.push_back(src);
}    

vector<string> findItinerary(vector<vector<string>>& tickets) {
      int sz = tickets.size();
      for(int i = 0; i < sz; i++){
          string x = tickets[i][0];
          string y = tickets[i][1];
          g[x].push(y);
      }
      DFS("JFK");
      reverse(ans.begin(),ans.end());
      return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<string>> tickets = {
      {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};

    auto ans = findItinerary(tickets);

    for(auto it : ans){
        cout << it << " ";
    }
}
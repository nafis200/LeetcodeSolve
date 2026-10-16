// 0 - 3 months:
// Amazon (18) — Meta (5) — Google (4) — Microsoft (3) — TikTok (3) — Bloomberg
// (2) — Rakuten (2) — Tekion (2) — Dream11 (2) — Yandex (2)

// 0 - 6 months:
// Lyft (21) — Oracle (3) — eBay (3) — Adobe (2) — Apple (2) — Flipkart (2) —
// Walmart Labs (2) — Goldman Sachs (2) — Uber (2) — PayPal (2)

// 6 months ago:
// Wix (8) — Intuit (8) — Samsung (6) — Zoho (4) — Docusign (4) — Nutanix (4) —
// ByteDance (3) — Salesforce (3) — PhonePe (3) — Informatica (3)

// problem_link: https://leetcode.com/problems/rotting-oranges/description/

#include <bits/stdc++.h>
using namespace std;

// time o(n * m) space o(1)

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

bool isValid(int i, int j, vector<vector<int>>& grid) {
  if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1) {
    return true;
  }
  return false;
}

int orangesRotting(vector<vector<int>>& grid) {
  n = grid.size();
  m = grid[0].size();
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 2) {
        q.push({i, j});
      }
    }
  }
  int steps = 0;
  
  while(!q.empty()){
      int sz = q.size();
      bool rotate = false;
      while(sz--){
         auto x = q.front();
         q.pop();
         int i = x.first;
         int j = x.second;
         for(int k = 0; k < 4; k++){
              int next_i = i + dx[k];
              int next_j = j + dy[k];
              if(isValid(next_i, next_j, grid)){
                 grid[next_i][next_j] = 2;
                 rotate = true;
                 q.push({next_i, next_j});
              }
         }
      }
      if(rotate){
        steps++;
      }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 1) {
        return -1;
      }
    }
  }
  return steps;

    
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
  int ans = orangesRotting(grid);
  cout << ans << "\n";
}
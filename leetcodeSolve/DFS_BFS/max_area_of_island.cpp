
// 0 - 3 months:
// Oracle (3) — Amazon (2) — Goldman Sachs (2) — Snowflake (2)

// 0 - 6 months:
// Meta (10) — Google (3) — Zoho (3) — Bloomberg (2)

// 6 months ago:
// Microsoft (13) — TikTok (12) — LinkedIn (8) — DoorDash (7) — Grubhub (3) —
// Adobe (2) — Apple (2) — Tesla (2) — Uber (2) — Intuit (2)

// Problem_Link: https://leetcode.com/problems/max-area-of-island/


// time o(n * m) space o(1)

#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

bool isValid(int i, int j, vector<vector<int>>& grid){
    if(i >= 0 && i < n && j >=0 && j < m && grid[i][j] != 0){
        return true;
    }
    return false;
}

int DFS(int i, int j, vector<vector<int>>&grid){
     grid[i][j] = 0;
     int ans = 1;
     for(int k = 0; k < 4; k++){
        int next_i = i + dx[k];
        int next_j = j + dy[k];
        if(isValid(next_i,next_j,grid)){
            ans += DFS(next_i, next_j, grid);
        }
     }
     return ans;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
     n = grid.size();
     m = grid[0].size();
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1){
                ans = max(ans, DFS(i, j, grid));
            }
        }
    }
    return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                              {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                              {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
  int ans = maxAreaOfIsland(grid);
  cout << ans << "\n";
}
// 0 - 3 months:
// Google (5) — Flipkart (2)

// 0 - 6 months:
// Amazon (6) — Meta (3)

// 6 months ago:
// TikTok (7) — ServiceNow (5) — Microsoft (4) — Uber (4) — Bloomberg (3) —
// Adobe (3) — Nutanix (2) — Urban Company (2)

// problem_Link:
// https://leetcode.com/problems/pacific-atlantic-water-flow/description/

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

bool isValid(int i, int j, int next_i, int next_j, vector<vector<int>>& heights,vector<vector<bool>>&vis){
     if(next_i >= 0 && next_i < n && next_j >= 0 && next_j < m && vis[next_i][next_j] == false && heights[next_i][next_j] >= heights[i][j]){
         return true;
     }
     return false;
}

void DFS(int i, int j,vector<vector<int>>& heights,vector<vector<bool>>&vis){
     vis[i][j] = true;
     for(int k = 0; k < 4; k++){
        int next_i = i + dx[k];
        int next_j = j + dy[k];
        if(isValid(i, j, next_i, next_j, heights, vis)){
            DFS(next_i, next_j, heights, vis);
        }
     }
}
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    n = heights.size();
    m = heights[0].size();
    vector<vector<bool>>pac(n, vector<bool>(m , false));
    vector<vector<bool>>atl(n, vector<bool>(m , false));

    for(int i = 0; i < n; i++){
        if(!pac[i][0]){
            DFS(i, 0, heights, pac);
        }
    }

    for(int i = 0; i < m; i++){
        if(!pac[0][i]){
            DFS(0, i, heights, pac);
        }
    }

    for(int i = 0; i < m; i++){
        if(!atl[n - 1][i]){
            DFS(n - 1, i, heights, atl);
        }
    }

    for(int i = 0; i < n; i++){
        if(!atl[i][m - 1]){
          DFS(i, m - 1, heights, atl);
        }
    }
    vector<vector<int>>ans;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(pac[i][j] && atl[i][j]){
                ans.push_back({i, j});
            }
        }
    }

 return ans;
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> heights = {{1, 2, 2, 3, 5},
                                 {3, 2, 3, 4, 4},
                                 {2, 4, 5, 3, 1},
                                 {6, 7, 1, 4, 5},
                                 {5, 1, 1, 2, 4}};

   vector<vector<int>>ans = pacificAtlantic(heights);

   for(auto v : ans){
      for(auto i : v){
        cout << i << " ";
      }
      cout << "\n";
   }
}
#include <bits/stdc++.h>
using namespace std;

// Time o(n^2 * logn) space o(n^2)

int n, m;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};



// bool isValid(vector<vector<int>>& grid, int i, int j,vector<vector<bool>>& vis){
//      if(i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == false){
//          return true;
//      }
//      return false;
// }

// bool CanReach(vector<vector<int>>& grid, int needTime){
//       vector<vector<bool>>vis(n, vector<bool>(m, false));
//       if(grid[0][0] > needTime){
//         return false;
//       }

//       queue<pair<int,int>>q;
//       q.push({0, 0});
//       vis[0][0] = true;
//       while(!q.empty()){
//          auto x = q.front();
//          int i = x.first;
//          int j = x.second;
//          q.pop();
//          if(i == n - 1 && j == m - 1){
//             return true;
//          }
//          for(int k = 0; k < 4; k++){
//              int next_i = i + dx[k];
//              int next_j = j + dy[k];
//              if(isValid(grid, next_i, next_j, vis)){
//                  if(grid[next_i][next_j] <= needTime){
//                     q.push({next_i, next_j});
//                     vis[next_i][next_j] = true;
//                  }
//              }
//          }
//       }
//       return false;
// }



// int swimInWater(vector<vector<int>>& grid) {
//     n = grid.size();
//     m = grid.size();       
//     int l = 0, r = 1e9;
//     int ans = -1;
//     while(l <= r){
//         int mid = (l + r) / 2;
//         if(CanReach(grid, mid)){
//             r = mid - 1;
//             ans = mid;
//         }
//         else{
//             l = mid + 1;
//         }
//     } 
//     return ans;
// }

bool isValid(vector<vector<int>>& grid, int i, int j,vector<vector<bool>>& vis){
     if(i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == false){
         return true;
     }
     return false;
}

int swimInWater(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid.size(); 
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
    pq.push({grid[0][0],0,0});
    vector<vector<bool>>vis(n, vector<bool>(m, false));
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        int cost = x[0];
        int i = x[1];
        int j = x[2];
        if(i == n - 1 && j == m - 1){
            return cost;
        }
        for(int k = 0; k < 4; k++){
            int next_i = i + dx[k];
            int next_j = j + dy[k];
            if(isValid(grid,next_i,next_j,vis)){
                int newCost = max(cost, grid[next_i][next_j]);
                vis[next_i][next_j] = true;
                pq.push({newCost, next_i, next_j});

            }
        }
    }
    return -1;
  
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> grid = {{0, 1, 2, 3, 4},
                              {24, 23, 22, 21, 5},
                              {12, 13, 14, 15, 16},
                              {11, 17, 18, 19, 20},
                              {10, 9, 8, 7, 6}};
  int ans = swimInWater(grid);
  cout << ans << "\n";
}


#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
int n;

queue<pair<int,pair<int,int>>>q;

bool isValid(int i, int j, vector<vector<bool>>& vis) {
   if(i >= 0 && i < n && j >= 0 && j < n && vis[i][j] == false){
      return true;
   }
   return false;
}

void DFS(vector<vector<int>>& grid, vector<vector<bool>>& vis,int i, int j) {
    vis[i][j] = true;
    q.push({0, {i, j}});
    for(int k = 0; k < 4; k++){
         int next_i = i + dx[k];
         int next_j = j + dy[k];
         if(isValid(next_i, next_j, vis) && grid[next_i][next_j] == 1){
            DFS(grid, vis, next_i, next_j);
         }
    }
}

int shortestBridge(vector<vector<int>>& grid) {
   n = grid.size();
   vector<vector<bool>>vis(n, vector<bool>(n, false));
   int n = grid.size();
   bool found = false;
   for(int i = 0; i < n; i++){
     for(int j = 0; j < n; j++){
         if(grid[i][j] == 1){
            found = true;
            DFS(grid, vis, i, j);
         }
     }
     if(found){
        break;
     }
   }
   while(!q.empty()){
      auto x = q.front();
      q.pop();
      int cost = x.first;
      int i = x.second.first;
      int j = x.second.second;
      for(int k = 0; k < 4; k++){
          int next_i = i + dx[k];
          int next_j = j + dy[k];
          if(isValid(next_i, next_j, vis)){
             if(grid[next_i][next_j] == 1){
                return cost;
             }
             q.push({cost + 1, {next_i, next_j}});
                vis[next_i][next_j] = true;
          }
      }
   }
   return -1;

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> grid = {{0, 1, 0}, {0, 0, 0}, {0, 0, 1}};
  int ans = shortestBridge(grid);
  cout << ans << "\n";
}
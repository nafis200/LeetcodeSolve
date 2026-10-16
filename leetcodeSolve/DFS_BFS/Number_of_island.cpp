// 0 - 3 months:
// Amazon (47) — Google (26) — Bloomberg (23) — Meta (15) — Microsoft (13) —
// TikTok (12) — Uber (10) — Apple (8) — Anduril (6) — Oracle (4)

// 0 - 6 months:
// Adobe (5) — Yandex (5) — Tinkoff (4) — Nvidia (4) — Samsung (4) — PayPal (4)
// — Salesforce (4) — LinkedIn (3) — Goldman Sachs (3) — Whatnot (3)

// 6 months ago:
// Zoho (9) — Yahoo (9) — Tesla (8) — ByteDance (7) — Intel (7) — Flipkart (5) —
// Walmart Labs (5) — Siemens (5) — eBay (5) — Snap (5)

// problem link: https://leetcode.com/problems/number-of-islands/description/

#include <bits/stdc++.h>
using namespace std;

// time o(n * m) space o(n * m)

// int dx[4] = {-1, 0, 1, 0};
// int dy[4] = {0, 1, 0, -1};

// bool isValid(vector<vector<char>>& grid, int i, int j,
//              vector<vector<bool>>& visited) {
//   int row = grid.size();
//   int col = grid[0].size();
//   if (i >= 0 && i <= row - 1 && j >= 0 && j <= col - 1 &&
//       visited[i][j] == false && grid[i][j] != '0') {
//     return true;
//   }
//   return false;
// }

// void DFS(vector<vector<char>>& grid, int i, int j,vector<vector<bool>>& visited){
//     visited[i][j] = true;
//     for(int k = 0; k < 4; k++){
//         int next_i = i + dx[k];
//         int next_j = j + dy[k];
//         if(isValid(grid, next_i, next_j, visited)){
//            DFS(grid, next_i, next_j, visited);   
//         }
//     }
// }

// int numIslands(vector<vector<char>>& grid) {
//   vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(), false));

//   int row = grid.size();
//   int col = grid[0].size();
//   int ans = 0;

//   for(int i = 0; i < row; i++){
//      for(int j = 0; j < col; j++){
//          if(visited[i][j] == false && grid[i][j] != '0'){
//             DFS(grid, i, j, visited);
//             ans++;
//          }
//      }
//   }

//   return ans;

// }

// time o(n * m) space o(1)

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool isValid(vector<vector<char>>& grid, int i, int j) {
  int row = grid.size();
  int col = grid[0].size();
  if (i >= 0 && i <= row - 1 && j >= 0 && j <= col - 1 && grid[i][j] != '0') {
    return true;
  }
  return false;
}

void DFS(vector<vector<char>>& grid, int i, int j){
    grid[i][j] = '0';
    for(int k = 0; k < 4; k++){
        int next_i = i + dx[k];
        int next_j = j + dy[k];
        if(isValid(grid, next_i, next_j)){
           DFS(grid, next_i, next_j);   
        }
    }
}

int numIslands(vector<vector<char>>& grid) {

  int row = grid.size();
  int col = grid[0].size();
  int ans = 0;

  for(int i = 0; i < row; i++){
     for(int j = 0; j < col; j++){
         if(grid[i][j] != '0'){
            DFS(grid, i, j);
            ans++;
         }
     }
  }

  return ans;

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<char>> grid = {
    {'1','1','0','0','0'},
    {'1','1','0','0','0'},
    {'0','0','1','0','0'},
    {'0','0','0','1','1'}
};

    int ans = numIslands(grid);
    cout << ans << "\n";
}
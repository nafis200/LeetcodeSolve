

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> memo;

int dp(int i, int j, vector<vector<int>>& grid) {
    if(i == n - 1 && j == m - 1){
        return grid[i][j];
    }
    if(i == n || j == m){
        return 1e9;
    }
    if(memo[i][j] != -1){
         return memo[i][j];
    }
    int down = dp(i + 1, j, grid);
    int right = dp(i, j + 1, grid);
    int ans = min(down, right) + grid[i][j];
    return ans;
}

int minPathSum(vector<vector<int>>& grid) {
  n = grid.size();
  m = grid[0].size();
  memo.assign(n + 1, vector<int>(m + 1, -1));
  int ans = dp(0, 0, grid);
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  int ans = minPathSum(grid);
  cout << ans << "\n";
}
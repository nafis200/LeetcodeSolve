

#include <bits/stdc++.h>
using namespace std;



const int inf = 1e9;
const int ninf = -1e9;
vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
int n;
int m;
bool isValid(int i, int j, vector<vector<int>>& grid){
   if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != 1){
       return true;
   }
   return false;
}

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
  int ans = shortestPathBinaryMatrix(grid);
  cout << ans << "\n";
}
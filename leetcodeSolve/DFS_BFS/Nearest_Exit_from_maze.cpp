// 0 - 3 months:
// Amazon (2)

// 0 - 6 months:
// Meta (3)

// 6 months ago:
// Google (6) — Uber (3) — Microsoft (2) — Samsung (2)

// problem_Link:
// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/

#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
int n;
int m;
bool isValid(int i, int j, vector<vector<char>>& grid) {
  if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '+') {
    return true;
  }
  return false;
}

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
   n = maze.size();
   m = maze[0].size();
  queue<pair<pair<int, int>, int>> q;
  maze[entrance[0]][entrance[1]] = '+';
  q.push({{entrance[0], entrance[1]}, 0});

  while (!q.empty()) {
    auto it = q.front();
    q.pop();
    int x = it.first.first;
    int y = it.first.second;
    int step = it.second;
    for (int i = 0; i < n; i++) {
      if (x == i && y == 0 && !(x == entrance[0] && y == entrance[1])) {
        return step;
      }

      if (x == i && y == m - 1 && !(x == entrance[0] && y == entrance[1])) {
        return step;
      }
    }

    for (int i = 0; i < m; i++) {
      if (x == 0 && y == i && !(x == entrance[0] && y == entrance[1])) {
        return step;
      }
      if (x == n - 1 && y == i && !(x == entrance[0] && y == entrance[1])) {
        return step;
      }
    }

    for(int k = 0; k < 4; k++){
        int next_i = x + dx[k];
        int next_j = y + dy[k];
        if(isValid(next_i, next_j, maze)){
            maze[next_i][next_j] = '+';
            q.push({{next_i, next_j}, step + 1});
        }
    }
  }
  return -1;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<char>> maze = {
      {'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};

  vector<int> entrance = {1, 2};

  int ans = nearestExit(maze, entrance);
  cout << ans << "\n";
}
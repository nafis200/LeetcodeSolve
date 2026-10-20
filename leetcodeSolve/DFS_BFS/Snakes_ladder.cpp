
//  row = n - 1 - (num - 1 / n);

//  col = (n - 1) % n;

//  ((num - 1) / n) % 2 == 1

//  col = n - 1 - col

// 0 - 3 months:
// Amazon (5) — Google (2) — Microsoft (2)

// 0 - 6 months:
// Meta (4) — Zomato (2)

// 6 months ago:
// Bloomberg (4) — Apple (4) — Goldman Sachs (3) — Oracle (2) — TikTok (2) —
// Cisco (2) — Pinterest (2) — Anduril (2)

// https://leetcode.com/problems/snakes-and-ladders/description/

#include <bits/stdc++.h>
using namespace std;

// time o(n^2) space o(n^2)

pair<int, int> getPos(int num, int n) {
    int row = n - 1 - ((num - 1) / n);
    int col = (num - 1) % n;
    int rowReverse = (num - 1) / n;
    if(rowReverse % 2 == 1){
       col = n - 1 - col;        
    } 
    return {row, col};
}

int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    vector<int>dis(n * n + 2, 1e9);
    dis[1] = 0;
    queue<int>q;
    q.push(1);
    while(!q.empty()){
         int x = q.front();
         q.pop();
         for(int dice = 1; dice <= 6; dice++){
             int next= x + dice;
             if(next > n * n){
                 break;
             }
             auto it = getPos(next, n);
             int row = it.first;
             int col = it.second;
             if(board[row][col] != -1){
                next = board[row][col];
             }
             if(dis[next] > dis[x] + 1){
                dis[next] = dis[x] + 1;
                q.push(next);
             }
         }
    }
    if(dis[n * n] == 1e9){
        return -1;
    }
    return dis[n * n];
}

int main() {
  vector<vector<int>> board = {
      {-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1}, {-1, 35, -1, -1, 13, -1},
      {-1, -1, -1, -1, -1, -1}, {-1, 15, -1, -1, -1, -1}};

      cout << snakesAndLadders(board) << "\n";

  return 0;
}

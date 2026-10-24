
#include <bits/stdc++.h>
using namespace std;


void rotate(vector<vector<int>>& matrix) {
     int row = matrix.size();
     int col = matrix[0].size();

     for(int i = 0; i < row; i++){
        for(int j = i; j < col; j++){
             swap(matrix[i][j], matrix[j][i]);
        }
     }
     for(int i = 0; i < row; i++){
         reverse(matrix[i].begin(), matrix[i].end());
     }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  rotate(matrix);
  int row = matrix.size();
  int col = matrix[0].size();
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }
}
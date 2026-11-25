
// (0,0) (0,1) (0,2) (0,3)
// (1,0) (1,1) (1,2) (1,3)
// (2,0) (2,1) (2,2) (2,3)
// (3,0) (3,1) (3,2) (3,3)


#include<bits/stdc++.h>
using namespace std;

// Time complexity n! space (number of solution * n^2)

vector<vector<string>>result;
vector<int>col, dia1, dia2;
void f(vector<string>board, int n, int row){
   if(row == n){
     result.push_back(board);
     return;
   }
   
   for(int c = 0; c < n; c++){
       if(col[c] == 0 && dia1[n + row - c] == 0 && dia2[row + c] == 0){
           col[c] = 1;
           dia1[n + row - c] = 1;
           dia2[row + c] = 1;
           board[row][c] = 'Q';
           f(board, n, row + 1);
           col[c] = 0;
           dia1[n + row - c] = 0;
           dia2[row + c] = 0;
           board[row][c] = '.';
       }
   }
}

vector<vector<string>> solveNQueens(int n) {
    vector<string>board(n, string(n, '.'));
    col.assign(2 * n + 1, 0);
    dia1.assign(2 * n + 1, 0);
    dia2.assign(2 * n + 1, 0);
    f(board, n, 0);
    return result;
}
int32_t main(){
    int n = 4;
    
    vector<vector<string>> ans = solveNQueens(n);

    for(auto s : ans){
        for(auto i : s){
            cout << i << " ";
        }
        cout << "\n";
    }

}

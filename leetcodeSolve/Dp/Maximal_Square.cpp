// 0 - 3 months:
// Google (5) — Microsoft (4) — Amazon (3) — ByteDance (2)

// 0 - 6 months:
// Flipkart (2) — Booking.com (2)


#include <bits/stdc++.h>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
     int mx = 0;
    vector<vector<int>>memo(n + 2, vector<int>(m + 2, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
             if(matrix[i][j] == '1'){
                 memo[i][j] = 1;
                 mx = 1;
             }
        }
    }

   
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(memo[i][j]){
                int x = memo[i - 1][j];
                int y = memo[i][j - 1];
                int z = memo[i - 1][j - 1];
                memo[i][j] = max(memo[i][j], min({x, y, z}) + 1);
                mx = max(mx, memo[i][j]);
            }
        }
    }
    return 1LL * mx * mx;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    cout << maximalSquare(matrix);

    return 0;
}


//  2 3 -1 -4

//  24
//  -4

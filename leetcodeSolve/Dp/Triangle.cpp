

#include <bits/stdc++.h>
using namespace std;



int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    int m = triangle[0].size();
    vector<int>memo(n + 1, 0);
    memo[0] = triangle[0][0];
    for(int i = 1; i < n; i++){
        for(int j = i; j >= 0; j--){
            if(j == i){
                memo[j] = memo[j - 1] + triangle[i][j];
            } 
            else if(j == 0){
                memo[j] = memo[j] + triangle[i][j];
            } 
            else{
                int left = triangle[i][j] + memo[j];
                int right = triangle[i][j] + memo[j - 1];
                memo[j] = min(left, right);
            }
        }
    }
    int ans = 1e9;
    for(int i = 0; i < n; i++){
        ans = min(ans, memo[i]);
    }
    return ans;
 }

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  int ans = minimumTotal(triangle);
  cout << ans << "\n";

}
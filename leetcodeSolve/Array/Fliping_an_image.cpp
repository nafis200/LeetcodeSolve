
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
  
  int rows = image.size();
  int cols = image[0].size();
  for(int i = 0; i < rows; i++){
     for(int j = 0; j < (cols + 1) / 2; j++){
        if(image[i][j] == image[i][cols - j - 1]){
             image[i][j] = image[i][cols - j - 1] = image[i][j] ^ 1;
        }
     }
  }
  return image;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> image = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};

  auto it = flipAndInvertImage(image);

  int rows = image.size();
  int cols = image[0].size();

  for (int i = 0; i < rows; i++) {
    cout << "[";
    for (int j = 0; j < cols; j++) {
      cout << image[i][j] << " ";
    }
    cout << "]";
  }
}

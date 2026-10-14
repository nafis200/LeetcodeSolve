#include <bits/stdc++.h>
using namespace std;

bool ok = true;

void DFS(vector<vector<int>>&g, vector<bool>&vis, vector<int>&col, int src, int color){
      vis[src] = true;
      col[src] = color;
      for(auto v : g[src]){
        if(vis[v] == false){
            int x = col[src] ^ 1;
            DFS(g, vis, col, v, x);
        }
        else if(col[v] == col[src]){
            ok = false;
            return;
        }
      }
}


bool isBipartite(vector<vector<int>>& graph) {
   int n = graph.size();
   vector<vector<int>>g(n + 1);

   for(int i = 0; i < graph.size(); i++){
        int k = graph[i].size();
        for(int j = 0; j < k; j++){
            g[i].push_back(graph[i][j]);
        }
   }

   vector<bool>vis(n + 1, false);
   vector<int>col(n + 1, 0);
   for(int i = 0; i < n; i++){
     if(vis[i] == false){
        DFS(g,vis,col,i,0);
     }
   }
   return ok;
   
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
  bool ans = isBipartite(graph);
  cout << ans << "\n";
}
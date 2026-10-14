#include <bits/stdc++.h>
using namespace std;

bool ok = false;

void DFS(vector<vector<int>>&g, int src, vector<bool>&vis, int par){
     vis[src] = true;
     for(auto v : g[src]){
        if(vis[v] == false){
            DFS(g, v, vis, src);
        }
        else if(vis[v] == true && v != par){
            ok = true;
            return;
        }
     }
     
}

bool validTree(int n, vector<vector<int>>& edges) {
    
    vector<vector<int>>g(n + 10);
    vector<bool>vis(n + 10, false);
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int components = 0;

    for(int i = 0; i < n; i++){
        if(vis[i] == false){
            DFS(g, i, vis, -1);
            components++;
        }
    }
  
     if(components == 1 && !ok){
        return true;
     }
     return false;

}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n = 4;
  vector<vector<int>> edges = {
      {0, 1},{2, 3}
  };

  bool ans = validTree(n, edges);
  cout << ans << "\n";
}
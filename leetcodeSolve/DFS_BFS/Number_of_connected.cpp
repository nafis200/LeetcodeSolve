#include<bits/stdc++.h>
using namespace std;

void DFS(int node,vector<bool>&vis, vector<vector<int>>&g){
     vis[node] = true;
     for(auto v : g[node]){
         if(!vis[v]){
            DFS(v, vis,g);
         }
     }
}

int countComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>>g(n);
    vector<bool>vis(n,false);
    int sz = edges.size();
    for(int i = 0; i < sz; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
         if(!vis[i]){
            DFS(i, vis,g);
            ans++;
         }
    }
    return ans;

}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> edges = {
    {0, 1},
    {1, 2},
    {2, 3},
    {3, 4}
};
int n = 5;

int ans = countComponents(n, edges);
cout << ans << "\n";
}
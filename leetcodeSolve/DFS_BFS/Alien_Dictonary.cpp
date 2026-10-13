

#include <bits/stdc++.h>
using namespace std;

string alienOrder(vector<string>& words) {
  int n = words.size();
  unordered_map<char, vector<char>> graph;
  unordered_map<char, int> indeg;
  unordered_map<char, bool> vis;
  string ans = "";
  for (auto s : words) {
    for (auto i : s) {
      indeg[i] = 0;
      vis[i] = false;
    }
  }
  int total_char = indeg.size();
  for (int i = 1; i < n; i++) {
    string a = words[i - 1];
    string b = words[i];
    int n1 = a.size();
    int m1 = b.size();

    if (n1 > m1 && a.substr(0, m1) == b) {
      ans = "";
      return ans;
    }
    for (int j = 0; j < min(n1, m1); j++) {
      if (a[j] != b[j]) {
        graph[a[j]].push_back(b[j]);
        indeg[b[j]]++;
        break;
      }
    }
  }
  vector<char>z;
  for(auto i : indeg){
     if(i.second == 0){
        z.push_back(i.first);
        vis[i.first] = true;
     }
  }
  vector<char>ansString;
  while(ansString.size() < total_char && z.size() > 0){
     char x = z.back();
     z.pop_back();
     ansString.push_back(x);
     for(auto i : graph[x]){
         indeg[i]--;
         if(indeg[i] == 0 && vis[i] == false){
              z.push_back(i);
              vis[i] = true;
         }
     }
  }

  if(ansString.size() != total_char){
     ans = "";
  }
  else{
     for(auto i : ansString){
         ans += i;
     }
  }
  return ans;
}

int32_t main() {
  vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
  string ans = alienOrder(words);

  cout << ans << "\n";
}
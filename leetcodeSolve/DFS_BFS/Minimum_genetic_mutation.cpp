

#include <bits/stdc++.h>
using namespace std;

vector<char> ch = {'A', 'C', 'G', 'T'};
int minMutation(string startGene, string endGene, vector<string>& bank) {
  set<string>BankGene;
  for(auto i : bank){
     BankGene.insert(i);
  }
  queue<pair<string,int>>q;
  if(startGene == endGene){
    return 0;
  }
  if(BankGene.find(endGene) == BankGene.end()){
     return -1;
  }
  q.push({startGene, 0});
  while(!q.empty()){
     string dna = q.front().first;
     int step = q.front().second;
     q.pop();

     if(dna == endGene){
        return step;
     }
     
     int genelength = dna.size();
     for(int i = 0; i < genelength; i++){
        string originalDna = dna;
        for(int j = 0; j < 4; j++){
           originalDna[i] = ch[j];
           if(BankGene.find(originalDna) != BankGene.end()){
                  q.push({originalDna, step + 1});
                  BankGene.erase(originalDna);
           }
        }
     }
  }
  return -1;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string startGene = "AACCGGTT";
  string endGene = "AAACGGTA";

  vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
  int ans = minMutation(startGene, endGene, bank);
  cout << ans << "\n";
}
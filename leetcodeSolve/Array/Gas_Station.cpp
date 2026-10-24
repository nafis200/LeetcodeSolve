

#include <bits/stdc++.h>
using namespace std;
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  int n = gas.size();
  int total_cost = 0;
  for(int i = 0; i < n; i++){
      total_cost += (gas[i] - cost[i]);
  }
  if(total_cost < 0){
     return -1;
  }

  int start_point = 0;
  int total_gas = 0;
  for(int i = 0; i < n; i++){
        total_gas += gas[i] - cost[i];
        if(total_gas < 0){
            total_gas = 0;
            start_point = i;
        }
  }
  return start_point;
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> gas = {2, 3, 4};
  vector<int> cost = {3, 4, 3};
  cout << canCompleteCircuit(gas, cost) << "\n";
}


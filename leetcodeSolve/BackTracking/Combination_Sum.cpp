#include<bits/stdc++.h>
using namespace std;


vector<vector<int>>result;
vector<int>a;

// Time Complexity o(2^(t / min_number) + 1)

void f(vector<int>& candidates, int target, int n, int sum, int i) {
    if(sum == target){
        result.push_back(a);
        return;
    }
    if(sum > target){
        return;
    }
 
    for(int j = i; j < n; j++){
        if(j != 0 && candidates[j] == candidates[j - 1]){
            continue;
        }
        if(sum + candidates[j] <= target){
            a.push_back(candidates[j]);
            f(candidates, target, n, sum + candidates[j], j);
            a.pop_back();
        }
    }

}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        f(candidates,target, n, 0, 0);
        return result;

}
int32_t main(){
    
    vector<int>candidates = {2,3,6,7};
    int target = 7;

    vector<vector<int>>ans = combinationSum(candidates, target);

    for(auto v : ans){
        cout << "[";
        for(auto i : v){
            cout << i << " ";
        }
        cout << "]\n";
    }
}

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>result;

int n;

void solve(int i, vector<int>& nums, vector<int>&ans){
     if(i == n){
        result.push_back(ans);
        return;
     }
     solve(i + 1, nums, ans);
     if(i < n){
         ans.push_back(nums[i]);
         solve(i + 1, nums, ans);
         ans.pop_back();
     }
}

vector<vector<int>> subsets(vector<int>& nums) {
      n = nums.size();  
      vector<int>ans;
      solve(0, nums, ans);
      return result;
}
int32_t main(){
    vector<int>nums = {1, 2, 3};
    vector<vector<int>> ans = subsets(nums);
    sort(ans.begin(),ans.end());
    for(auto v : ans){
        cout << "[";
        for(auto i : v){
            cout << i << " ";
        }
        cout << "]\n";
    }
}
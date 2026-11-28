#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
vector<int> temp;
int n;

void BrackTrack(int idx,vector<int>& nums) {
    ans.push_back(temp);
    if(idx == n){
        return;
    }
    for(int i = idx; i < n; i++){
        if(i > idx && nums[i] == nums[i - 1]){
            continue;
        }
        temp.push_back(nums[i]);
        BrackTrack(i + 1, nums);
        temp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) 
{ 
    n = nums.size();
    sort(nums.begin(), nums.end()); 
    BrackTrack(0, nums);
    return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {1, 2, 2};

  vector<vector<int>> ans = subsetsWithDup(nums);
  for (auto v : ans) {
    cout << "[";
    for (auto i : v) {
      cout << i << " ";
    }
    cout << "] ";
  }
}
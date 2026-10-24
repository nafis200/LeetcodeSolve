
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>missingRange(vector<int>&nums, int lower, int upper){
    vector<vector<int>>ans;
    if(lower != nums[0]){
        ans.push_back({lower, nums[0] - 1});
        lower = nums[0];
    }
    int n = nums.size();
    for(int i = 1; i < n; i++){
        if(nums[i] - 1 != lower){
            ans.push_back({lower + 1, nums[i] - 1});
            lower = nums[i];
        }
        else{
            lower = nums[i];
        }
    }
    if(nums[n - 1] != upper){
        ans.push_back({nums[n - 1] + 1, upper});
    }
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int lower = 0, upper = 99;
    vector<int>nums = {0, 1, 3, 50, 75};
    auto ans = missingRange(nums, lower, upper);
    for(auto v : ans){
        cout << "[";
        for(auto i : v){
            cout << i << " ";
        }
        cout << "\n";
    }
}
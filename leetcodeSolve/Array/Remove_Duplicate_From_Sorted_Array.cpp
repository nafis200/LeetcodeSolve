

#include<bits/stdc++.h>
using namespace std;

//  1 2 2

int removeDuplicates(vector<int>& nums){
    int n = nums.size();
    int j = 0;
    for(int i = 1; i < n; i++){
         if(nums[j] != nums[i]){
             j++;
             nums[j] = nums[i];
         }
    }
    return j + 1;
}



int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int>nums = {1,2,2};

    int ans = removeDuplicates(nums);
    
    cout << ans << "\n";
    for(auto it : nums){
       cout << it << " ";
    }
    
}
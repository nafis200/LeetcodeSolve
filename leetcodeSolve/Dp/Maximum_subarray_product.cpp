
#include<bits/stdc++.h>
using namespace std;
// int maxProduct(vector<int>& nums) {
//     int n = nums.size();
//     int ans = nums[0];
//     for(int i = 0; i < n; i++){
//         int product = 1;
//         for(int j = i; j < n; j++){
//              product = product * nums[j];
//              ans = max(ans, product);
//         }
//     }
//     return ans;
// }

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int mx = nums[0];
    int mn = nums[0];
    int ans = nums[0];
    for(int i = 1; i < n; i++){
        if(nums[i] < 0){
            swap(mn, mx);
        }
        mx = max(nums[i], mx * nums[i]);
        mn = min(nums[i], mn * nums[i]);
        ans = max(ans, mx);
    }
    return ans;
    
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {-2, 0, -1};
    cout << maxProduct(nums) << "\n";
}
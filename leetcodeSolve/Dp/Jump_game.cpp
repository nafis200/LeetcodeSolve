
#include<bits/stdc++.h>
using namespace std;
bool canJump(vector<int>& nums) {
    int n = nums.size();
    int current_step = 0;
    int step = 0;
    int total_step;
    for(int i = 0; i < n; i++){
        total_step = max(total_step, i + nums[i]);

        if(current_step == i){
            current_step = total_step;
            step++;
        }
    }
    if(current_step >= n - 1){
        return true;
    }
    return false;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {2,3,1,1,4};

    cout << canJump(nums) << "\n";
}
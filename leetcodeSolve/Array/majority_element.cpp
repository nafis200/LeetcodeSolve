
//  3 3 4

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
     int n = nums.size();   
     int mx = nums[0];
     int power = 0;
     for(int i = 0; i < n; i++){
         if(power == 0){
            mx = nums[i];
        }
        if(nums[i] == mx){
            power++;
        }
        else{
            power--;
        }
       
     }     
     return mx;
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int>nums={3,2,3};

  int ans = majorityElement(nums);
  cout << ans << "\n";
  
}


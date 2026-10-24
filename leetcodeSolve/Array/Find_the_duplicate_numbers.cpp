
#include<bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int>& nums) {
      int slow = nums[0];
      int fast = nums[nums[0]];
      while(slow != fast){
         slow = nums[slow];
         fast = nums[nums[fast]];
      }  
      fast = 0;
      while(slow != fast){
         slow = nums[slow];
         fast = nums[fast];
      }
      return slow;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

  vector<int> nums = {3, 1, 3, 4, 2};
  int ans = findDuplicate(nums);
  cout << ans << "\n";
}
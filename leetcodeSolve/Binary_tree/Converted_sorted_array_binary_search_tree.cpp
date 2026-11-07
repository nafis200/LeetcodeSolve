

#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public: 
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode* build(vector<int>&nums, int l, int r){
    if(l > r){
        return NULL;
    }
    int mid = l + (r - l) / 2;
    TreeNode* root = new TreeNode(nums[mid]);

    root->left = build(nums, l, mid - 1);
    root->right = build(nums, mid + 1, r);
    return root;
}


TreeNode* sortedArrayToBST(vector<int>& nums) {
     int n = nums.size();
     return build(nums, 0, n - 1);
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>arr = {-10, -3, 0, 5, 9};

    TreeNode* root = sortedArrayToBST(arr);
    
}
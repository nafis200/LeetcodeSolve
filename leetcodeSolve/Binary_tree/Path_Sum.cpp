// 0 - 3 months:
// Apple (3) — Google (2) — Meta (2)

// 0 - 6 months:
// Bloomberg (3) — Microsoft (2) — Amazon (2)

// 6 months ago:
// Goldman Sachs (3) — Palo Alto Networks (2) — Datadog (2)

// Problem_Link: https://leetcode.com/problems/path-sum/


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

TreeNode* BuildTree(vector<int>&arr){
     if(arr.empty()){
        return NULL;
     }

     TreeNode* root = new TreeNode(arr[0]);
   
     queue<TreeNode*>q;
     q.push(root);
     int i = 1;
     while(!q.empty()){
        TreeNode* cur = q.front();
        q.pop();
        if(i < arr.size() && arr[i] != -1){
            cur->left = new TreeNode(arr[i]);
            q.push(cur->left);
        }
        i++;
        if(i < arr.size() && arr[i] != -1){
            cur->right = new TreeNode(arr[i]);
            q.push(cur->right);
        }
        i++;
     }
     return root;
}

bool hasPathSum(TreeNode* root, int targetSum) {
     if(root == NULL){
        return false;
     }
     if(root->left == NULL && root->right == NULL){
         if(targetSum - root->val == 0){
             return true;
         }
         return false;
     }
     return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>arr = {5,4,8,11,-1,13,4,7,2,-1,-1,-1,1};

    TreeNode* root = BuildTree(arr);
    bool ans = hasPathSum(root, 22);
    cout << ans << "\n";
    
}
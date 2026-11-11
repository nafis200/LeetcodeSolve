// Google (2) — Amazon (2) — Meta (2)

// Problem_Link: https://leetcode.com/problems/merge-two-binary-trees/description/

#include<bits/stdc++.h>
using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) {
    val = x;
    left = NULL;
    right = NULL;
  }
};

TreeNode* BuildTree(vector<int>& arr){
    if(arr.empty()){
        return NULL;
    }

    TreeNode* root = new TreeNode(arr[0]);

    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while(!q.empty() && i < arr.size()){
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

void preorder(TreeNode* root) {
    if (root == NULL) return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
   if(root1 == NULL && root2 == NULL){
      return NULL;
   }
   if(root1 != NULL && root2 == NULL){
     return root1;
   }
   if(root2 != NULL & root1 == NULL){
      return root2;
   }
   root1->val += root2->val;
   root1->left = mergeTrees(root1->left, root2->left);

   root1->right = mergeTrees(root1->right, root2->right);

   return root1;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int>arr = {1, 3, 2, 5};
    vector<int>arr1 = {2,1,3,-1,4,-1,7};

    TreeNode* root1 = BuildTree(arr);
    TreeNode* root2 = BuildTree(arr1);
    
    TreeNode* root = mergeTrees(root1, root2);
}
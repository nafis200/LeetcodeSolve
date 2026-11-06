// 0 - 6 months:
// Meta (4) — Amazon (3) — Microsoft (2)

// 6 months ago:
// Google (9) — Bloomberg (4) — Adobe (3) — Yahoo (2)

// Problem_Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

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

TreeNode* build(TreeNode* root, int val){
    if(root == NULL){
         return new TreeNode(val);
    }  
    if(root->val > val){
        root->left = build(root->left, val);
    }
    else{
        root->right = build(root->right,val);
    }
    return root;
    
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode* root = NULL;
    int n = preorder.size();
    for(int i = 0; i < n; i++){
        root = build(root, preorder[i]);
    }
    return root;
}

 void preoder(TreeNode* root){
    if(root == NULL){
        return;
    }
    cout << root->val << " ";
    preoder(root->left);
    preoder(root->right);
 }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>preorder = {8,5,1,7,10,12};

    TreeNode* root = bstFromPreorder(preorder);

    preoder(root);
    
}
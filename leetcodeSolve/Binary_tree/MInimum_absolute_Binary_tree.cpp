// 0 - 6 months:
// Google (3) — Meta (2)

// 6 months ago:
// Amazon (3) — Adobe (3) — Goldman Sachs (2)

// Problem_Link: https://leetcode.com/problems/minimum-absolute-difference-in-bst/

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

TreeNode* prevNode = NULL;
int ans = INT_MAX;

void InorderTraversal(TreeNode* root){
     if(root == NULL){
        return;
     }

     InorderTraversal(root->left);

     if(prevNode != NULL){
        ans = min(ans, abs(prevNode->val - root->val));
     }
     prevNode = root;

     InorderTraversal(root->right);
}

int getMinimumDifference(TreeNode* root) {
    InorderTraversal(root);
    return ans;
}



int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
}
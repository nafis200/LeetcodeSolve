#include <bits/stdc++.h>
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

TreeNode* BuildTree(vector<int>& arr) {
  if (arr.size() == 0) {
    return NULL;
  }
  TreeNode* root = new TreeNode(arr[0]);

  queue<TreeNode*> q;
  q.push(root);
  int i = 1;
  while (!q.empty()) {
    TreeNode* x = q.front();
    q.pop();
    if (i < (int)arr.size() && arr[i] != -1) {
      TreeNode* left = new TreeNode(arr[i]);
      x->left = left;
      q.push(left);
    }
    i++;
    if (i < (int)arr.size() && arr[i] != -1) {
      TreeNode* right = new TreeNode(arr[i]);
      x->right = right;
      q.push(right);
    }
    i++;
  }
  return root;
}

// Time Complexity without map

// o(n^2) space o(1)

// if map

// Time o(n) space o(1)

unordered_map<TreeNode*, int>mp;

int depth(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    if(mp.find(root) != mp.end()){
        return mp[root];
    }

    int leftHeight = depth(root->left);
    int rightHeight = depth(root->right);

    return mp[root] = max(leftHeight, rightHeight) + 1;
}


bool isBalanced(TreeNode* root){
    if(root == NULL){
        return true;
    }
   
    int leftHeight = depth(root->left);
    int rightHeight = depth(root->right);

    if(abs(leftHeight - rightHeight) > 1){
         return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int>arr = {3,9,20,-1,-1,15,7};
  TreeNode* root = BuildTree(arr);
  cout << isBalanced(root) << "\n";
  
}
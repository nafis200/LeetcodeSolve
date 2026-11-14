// 0 - 3 months:
// Meta (9) — Oracle (3)

// 0 - 6 months:
// Google (2)

// 6 months ago:
// Amazon (14) — Microsoft (10) — Bloomberg (2) — Visa (2)

// Problem_Link: https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
  if (arr.empty()) {
    return NULL;
  }

  TreeNode* root = new TreeNode(arr[0]);

  queue<TreeNode*> q;
  q.push(root);
  int i = 1;
  while (!q.empty()) {
    TreeNode* cur = q.front();
    q.pop();
    if (i < arr.size() && arr[i] != -1) {
      cur->left = new TreeNode(arr[i]);
      q.push(cur->left);
    }
    i++;
    if (i < arr.size() && arr[i] != -1) {
      cur->right = new TreeNode(arr[i]);
      q.push(cur->right);
    }
    i++;
  }
  return root;
}

// Time o(n) space o(h)

int sumNodes(TreeNode* root, int sum) {
     if(root == NULL){
        return 0;
     }
     if(root->left == NULL && root->right == NULL){
         return sum * 10 + root->val;
     }
     sum = sum * 10 + root->val;
    
     return sumNodes(root->left, sum) + sumNodes(root->right, sum);
}

int sumNumbers(TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    return sumNodes(root, 0);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr = {4, 9, 0, 5, 1};

  TreeNode* root = BuildTree(arr);

  int ans = sumNumbers(root);
  cout << ans << "\n";
}
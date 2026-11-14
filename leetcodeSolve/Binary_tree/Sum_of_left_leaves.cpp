// 0 - 3 months: Grammarly (2)
// 0 - 6 months: Meta (3) — Uber (2)
// 6 months ago: Amazon (7) — Bloomberg (5) — Adobe (3) — Yandex (3) — Google (2)

// Problem_Link: https://leetcode.com/problems/sum-of-left-leaves/description/

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

int sumOfLeftLeaves(TreeNode* root) {
      if(root == NULL){
        return 0;
      }
      
      int sum = 0;

      if(root->left && root->left->left == NULL && root->left->right == NULL){
        sum += root->val;
      }


      sum += sumOfLeftLeaves(root->left);
      sum += sumOfLeftLeaves(root->right);
      return sum;
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr = {3,9,20,-1,-1,15,7};
  TreeNode* root = BuildTree(arr);

  int ans = sumOfLeftLeaves(root);
 
  cout << ans << "\n";
}
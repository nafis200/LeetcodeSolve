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

// Time o(n) space o(n)

vector<vector<int>> levelOrder(TreeNode* root) {
  vector<vector<int>> ans;
  if(root == NULL){
    return ans;
  }  
  queue<TreeNode*>q;
  q.push(root);
  while(!q.empty()){
      int sz = q.size();
      vector<int>node;
      while(sz--){
          TreeNode* x = q.front();
          q.pop();
          if(x->left){
            q.push(x->left);
          }
          if(x->right){
            q.push(x->right);
          }
          node.push_back(x->val);
      }
      ans.push_back(node);
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr = {3, 9, 20, -1, -1, 15, 7};
  TreeNode* root = BuildTree(arr);

  vector<vector<int>> ans = levelOrder(root);

  for (auto v : ans) {
    for (auto i : v) {
      cout << i << " ";
    }
    cout << "\n";
  }
}
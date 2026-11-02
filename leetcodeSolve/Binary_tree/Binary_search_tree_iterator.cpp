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

// vector<int>InorderTraversal;
// int ptr;

// void Inorder(TreeNode* root){
//     if(root == NULL){
//         return;
//     }
//     Inorder(root->left);
//     InorderTraversal.push_back(root->val);
//     Inorder(root->right);
// }

// BSTIterator(TreeNode* root) {
//        Inorder(root);
//        ptr = 0; 
// }
    
// int next() {
//     return InorderTraversal[ptr++];
// }
    
// bool hasNext() {
//     return ptr < InorderTraversal.size();
// }





stack<TreeNode*>st;

void PushLeft(TreeNode* root){
    if(root == NULL){
        return;
    }
    st.push(root);
    PushLeft(root->left);
}

BSTIterator(TreeNode* root) {
    PushLeft(root);
}
    
int next() {
   TreeNode* x = st.top();
   st.pop();
   if(x->right){
     PushLeft(x->right);
   }
   return x->val;
}
    
bool hasNext() {
    return !st.empty();
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr = {7, 3, 15, -1, -1, 9, 20};
  TreeNode* root = BuildTree(arr);
}
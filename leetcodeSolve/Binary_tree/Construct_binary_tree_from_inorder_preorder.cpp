

// inorder

// left --> root --> right

// post order

// left --> right --> root

// 0 - 6 months:
// Amazon (3)

// 6 months ago:
// Microsoft (11) — Google (10) — Meta (3) — Walmart Labs (3) — Bloomberg (2)

// Problem_Link:
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

// Inorder --> left-->root-->right

// postorder ---> = Left -> Right -> Root

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

int idx;
unordered_map<int, int> mp;

TreeNode* build(vector<int>& inorder, vector<int>& postorder, int l, int r) {
        if(l > r){
            return NULL;
        }
        
        int val = postorder[idx--];
        int mid = mp[val];
        
        TreeNode* root = new TreeNode(val);

        root->right = build(inorder, postorder, mid + 1, r);
        root->left = build(inorder, postorder, l, mid - 1);
        return root;

        
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size() - 1;
    idx = n;
    for(int i = 0; i <= n; i++){
         mp[inorder[i]] = i;
    }

    return build(inorder, postorder, 0, n);

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<int> inorder = {9, 3, 15, 20, 7};

  vector<int> postorder = {9, 15, 7, 20, 3};

  TreeNode* root = buildTree(inorder, postorder);
}
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

TreeNode* BuildTree(vector<int>& arr){
    if(arr.empty()){
        return NULL;
    }
    int n = arr.size();
    queue<TreeNode*>q;
    TreeNode* root = new TreeNode(arr[0]);
    q.push(root);
    int i = 1;
    while(!q.empty()){
        TreeNode* x = q.front();
        q.pop();
        if(i < n && arr[i] != -1){
            x->left = new TreeNode(arr[i]);
            q.push(x->left);
        }
        i++;
        if(i < n && arr[i] != -1){
            x->right = new TreeNode(arr[i]);
            q.push(x->right);
        }
        i++;
    }
    return root;
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    
    unordered_map<TreeNode*, TreeNode*>mp;
    queue<TreeNode*>q;
    TreeNode* cur = root;
    q.push(root);
    while(!q.empty()){
        TreeNode* x = q.front();
        cur = x;
        q.pop();
        if(x->left != NULL){
            mp[x->left] = cur;
            q.push(x->left);
        }
        if(x->right != NULL){
            mp[x->right] = cur;
            q.push(x->right);
        }
    }

    unordered_set<TreeNode*>vis;
    vector<int>ans;
    q.push(target);
    vis.insert(target);
    int dis = 0;
    while(!q.empty()){
       if(dis == k){
         break;
       }
       int sz = q.size();
       while(sz--){
          TreeNode* x = q.front();
          q.pop();
          if(x->left != NULL && !vis.count(x->left)){
              q.push(x->left);
              vis.insert(x->left);
          }
          if(x->right != NULL && !vis.count(x->right)){
             q.push(x->right);
             vis.insert(x->right);
          }
          if(mp.count(x) && !vis.count(mp[x])){
             q.push(mp[x]);
             vis.insert(mp[x]);
          }
       }
       dis++;
    }
    while(!q.empty()){
        TreeNode* x = q.front();
        q.pop();
        ans.push_back(x->val);
    }
    return ans;
}



int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<int> arr = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};

  TreeNode* root = BuildTree(arr);
}
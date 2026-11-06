// 0 - 3 months:
// DoorDash (14) — Meta (12) — Google (9) — Amazon (7) — Microsoft (2) — TikTok (2)

// 0 - 6 months:
// Oracle (3) — tcs (2) — Apple (2) — Goldman Sachs (2) — Wix (2) — Uber (2) — Datadog (2) — Baidu (2)

// 6 months ago:
// Citadel (30) — Adobe (8) — Flipkart (7) — Yandex (7) — Bloomberg (5) — Nvidia (4) — Salesforce (4) — Arcesium (3) — Booking.com (3) — Yahoo (3)

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

//          5
//         / \
//       10   50 
//      /  \
//    20    30

//  20 --> 10 --> 30
//  20--> 10 --> 5 --> 50
//  30 --> 10 --> 5 -->50

int mx = INT_MIN;

int DFS(TreeNode* root){
    if(root == NULL){
        return 0;
    }

    int left = max(0, DFS(root->left));
    int right = max(0, DFS(root->right));

    int currentSum = root->val + left + right;
    
    mx = max(mx, currentSum);

    return max(root->val + left, root->val + right);

}


int maxPathSum(TreeNode* root) {
       int ans = DFS(root);
       return mx;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>arr = {-10,9,20,-1,-1,15,7};
    TreeNode* root = BuildTree(arr);
    cout << maxPathSum(root);

}
// 0 - 3 months:
// Amazon (3) — Google (2) — Bloomberg (2)

// 0 - 6 months:
// Meta (3)

// 6 months ago:
// Microsoft (10) — Media.net (7) — Uber (3) — Apple (2) — Oracle (2) — Myntra (2) — Anduril (2) — PayPal (2) — Salesforce (2) — Yahoo (2)

// Problem_Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

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

TreeNode* BuildTree(vector<int>&arr){
     if(arr.empty()){
        return NULL;
     }

     TreeNode* root = new TreeNode(arr[0]);
   
     queue<TreeNode*>q;
     q.push(root);
     int i = 1;
     while(!q.empty()){
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



//  Moris traversal
//       1
//     /   \
//    2     5
//   / \     \
//  3   4     6

//   1 left subtree right last node find
// then connect last right to main right

//      1
//      /
//     2
//    / \
//   3   4
//        \
//         5
//          \
//           6


//   1
//    \
//     2
//    / \
//   3   4
//        \
//         5
//          \
//           6


void flatten(TreeNode* root) {
    if(root == NULL){
        return;
    }     

    TreeNode* cur = root;
    while(cur != NULL){
        if(cur->left){
            TreeNode* prev = cur->left;

            while(prev->right != NULL){
                prev = prev->right;
            }

            prev->right = cur->right;

            cur->right = cur->left;
            cur->left = NULL;
        }
        cur = cur->right;
    }

}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>arr = {1,2,5,3,4,-1,6};

    TreeNode* root = BuildTree(arr);
       
}
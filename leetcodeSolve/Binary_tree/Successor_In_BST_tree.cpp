// 6 months ago:
// Docusign (3) — Google (2) — Meta (2) — Microsoft (2) — Amazon (2) — Pocket Gems (2)

// https://www.lintcode.com/problem/448

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


    //       20
    //      /  \
    //    10    30
    //   / \
    //  5  15
    //    /
    //   12

    //  10 successor 12
    //  12 successor 15
    //  20 successor 30

    // if right child then most left is answer
    // if not right then bigger root is answer

 TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        if(root == NULL){
            return NULL;
        }
        TreeNode* succesor = NULL;
        if(p->right){
            TreeNode* cur = p->right;
            while(cur->left != NULL){
                cur = cur->left;
            }
            return cur;
        }
        else{
            TreeNode* cur = root;
            
            while(cur != NULL){
                if(cur->val > p->val){
                    succesor = cur;
                    cur = cur->left;
                }
                else{
                   cur = cur->right;
                }
            }
        }
        return succesor;
    }   

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
}
// 0 - 3 months:
// Amazon (3) — Meta (2)

// 0 - 6 months:
// Google (6) — Bloomberg (3)

// 6 months ago:
// Microsoft (12) — Oracle (6) — Adobe (5) — Apple (3) — Nvidia (2) — Yahoo (2)


// Problem_Link: https://leetcode.com/problems/delete-node-in-a-linked-list/description/

#include<bits/stdc++.h>
using namespace std;

class ListNode{
   public: 
   int val;
   ListNode* next;
   ListNode(int val){
       this->val =val;
       next = NULL;
   }
};

ListNode* CreateNode(vector<int>&nums){
    ListNode* head = NULL;
    ListNode* temp = NULL;
    
    for(auto it : nums){
        ListNode* newnode = new ListNode(it);
        if(head == NULL){
             head = newnode;
             temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;

}

void Print(ListNode* head){
   while(head != NULL){
     cout << head->val << " ";
     head = head->next;
   }
}

ListNode* FindNode(int val, ListNode* head){
      ListNode* temp = head;
      while(temp != NULL){
         if(temp->val == val){
            return temp;
         }
         temp = temp->next;
      }
    return head;
}

//  1 2 3 4 5

//  1 2 4 4 5
 void deleteNode(ListNode* node) {
       ListNode* nextNode = node->next;
       node->val = nextNode->val;
       node->next = nextNode->next;
       delete nextNode;
  }


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {1, 2, 3, 4, 5};

    ListNode* head = CreateNode(nums);
    ListNode* Node = FindNode(3, head);

    deleteNode(Node);

    Print(head);

}




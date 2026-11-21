#include<bits/stdc++.h>
using namespace std;

class ListNode{
   public: 
   int val;
   ListNode* next; 
   ListNode(int val){ 
      this->val = val;
      this->next = NULL;
   }   
};

ListNode* CreateList(vector<int>&v1){
    ListNode* head = NULL;
    ListNode* tail = NULL;

    for(int x : v1){
       ListNode* newnode = new ListNode(x);
       if(head == NULL){
         head = newnode;
         tail = newnode;
       }
       else{
          tail->next = newnode;
          tail = newnode;
       }
    }
    return head;
}

ListNode* partition(ListNode* head, int x) {
     vector<int>small,big;
     ListNode* temp = head;
     while(temp != NULL){
         if(temp->val < x){
             small.push_back(temp->val);
         }
         else{
            big.push_back(temp->val);
         }
         temp = temp->next;
     }

     ListNode* head1 = CreateList(small);

     ListNode* head2 = CreateList(big);

     temp = head1;
     while(temp != NULL && temp->next != NULL){
         temp = temp->next;
     }
     if(temp){
         temp->next = head2;
     }
     if(head1){
         return head1;
     }
     return head2;
}
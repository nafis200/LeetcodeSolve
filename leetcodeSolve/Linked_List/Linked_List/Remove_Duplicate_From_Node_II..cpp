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

// 1 1 1 2 2 2 3 3 4 5

ListNode* deleteDuplicates(ListNode* head) {
      ListNode* prev = NULL;
      ListNode* temp = head;

    while(temp != NULL && temp->next != NULL){
        if(temp->val == temp->next->val){
            ListNode* del = temp;
            while(del != NULL && del->next != NULL && del->val == del->next->val){
                del = del->next;
            }
            if(prev == NULL){
                head = del->next;
            }
            else{
                prev->next = del->next;
            }
            temp = del->next;
        }
        else{
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}
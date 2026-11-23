
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


//  7 7 7 7

ListNode* removeElements(ListNode* head, int val) {
    if(head == NULL){
        return head;
    }        
    ListNode* prev = NULL;
    ListNode* temp = head;
    while(temp != NULL){
        bool ok = false;
        while(temp != NULL && temp->val == val){
             ok = true;
             temp = temp->next;
        }
        if(ok){
            if(prev == NULL){
                prev = temp;
                head = temp;
            }
            else{
                prev->next = temp;
            }
        }
        else{
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}





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


ListNode* Reverse(ListNode* head){
     ListNode* prev = NULL;
     ListNode* temp = head;
     while(temp != NULL){
        ListNode* cur = temp->next;
        temp->next = prev;
        prev = temp;
        temp = cur;   
     }
     return prev;
}

ListNode* removeNodes(ListNode* head) {
 
    if(head == NULL && head->next == NULL){
        return head;
    }

    head = Reverse(head);

    ListNode* temp = head;

    while(temp != NULL && temp->next != NULL){
        while(temp != NULL && temp->next != NULL && temp->val > temp->next->val){
             temp->next = temp->next->next;
        }
        temp = temp->next;
    }
    head = Reverse(head);
    return head;
}

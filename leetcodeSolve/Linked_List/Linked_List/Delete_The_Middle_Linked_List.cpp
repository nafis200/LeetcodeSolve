
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

//  1 2


ListNode* deleteMiddle(ListNode* head) {
     ListNode *prev = NULL;
     ListNode* first = head;
     ListNode* second = head;
     while(second != NULL && second->next != NULL){
        prev = first;
        first = first->next;
        second = second->next->next;
     }
   
     if(prev == NULL){
        return NULL;
     }
     
     prev->next = first->next;
     return head;
}


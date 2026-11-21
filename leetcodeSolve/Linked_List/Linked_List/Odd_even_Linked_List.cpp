

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


ListNode* oddEvenList(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
   
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenSave = head->next;

    while(even != NULL && even->next != NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenSave;
    return head;
}



//  1 2  2 1


// slow = 2

// fast = NULL



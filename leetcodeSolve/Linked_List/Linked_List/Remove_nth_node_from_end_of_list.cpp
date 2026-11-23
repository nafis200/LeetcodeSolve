
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

//  ListNode* removeNthFromEnd(ListNode* head, int n) {
//     if(head == NULL){
//         return head;
//     }
//     int cnt = 0;
//     ListNode* temp = head;
//     while(temp != NULL){
//         cnt++;
//         temp = temp->next;
//     }

//     int stop = cnt - n;
//     temp = head;
//     if(n == cnt){
//         return head->next;
//     }
//     for(int i = 1; i < stop; i++){
//         temp = temp->next;
//     }
//     temp->next = temp->next->next;
//     return head;
//  }


ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head == NULL){
        return head;
    }
    
    ListNode* fast = head;
    ListNode* slow = head;

    for(int i = 1; i <= n; i++){
        fast = fast->next;
    }

    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    if(fast == NULL){
        head = slow->next;
    }
    else{
        slow->next = slow->next->next;
    }
    return head;
 }
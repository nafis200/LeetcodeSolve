
#include <bits/stdc++.h>
using namespace std;

class ListNode {
 public:
  int val;
  ListNode* next;
  ListNode(int val) {
    this->val = val;
    next = NULL;
  }
};

ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL || head->next == NULL){
        return head;
    }

    int cnt = 0;

    ListNode* temp = head;
    while(temp != NULL){
       cnt++;
       temp = temp->next;
    }
    k = k % cnt;
       if(k == 0){
        return head;
     }
    int pos = cnt - k;
    temp = head;
    for(int i = 1; i < pos; i++){
        temp = temp->next;    
    }

    ListNode* newHead = temp->next;
    temp->next = NULL;
    ListNode* newTemp = newHead;

    while(newTemp->next != NULL){
        newTemp = newTemp->next;
    }
    newTemp->next = head;
    return newHead;
    
}


//  1 2 3 4 5
//      i j  
//  1 --> 5 --> 2 --> 4 --> 3
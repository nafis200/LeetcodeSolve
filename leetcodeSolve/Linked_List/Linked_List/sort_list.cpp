

//  2  1

// prev = 2
//  mid = 1


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

ListNode* Getmid(ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* prev = NULL;
    while(fast != NULL){
        prev = slow;
        fast = fast->next->next;
        slow = slow->next;
    }

    if(prev){
        prev->next = NULL;
    }
    return slow;
}

ListNode* merge(ListNode* a, ListNode* b){
    ListNode* head = new ListNode(0);
    ListNode* temp = head;
    while(a != NULL && b != NULL){
        if(a->val <= b->val){
            temp->next = a;
            a = a->next;
        }
        else{
            temp->next = b;
            b = b->next;
        }
        temp = temp->next;
    }
    return head->next;
}

ListNode* sortList(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode* mid = Getmid(head);
    ListNode* left = sortList(head);
    ListNode* right = sortList(mid);
    return merge(left, right);
}
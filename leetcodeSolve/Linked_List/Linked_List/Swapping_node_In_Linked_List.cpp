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

ListNode* swapNodes(ListNode* head, int k) {
    if(head == NULL && head->next == NULL){
        return head;
    }

    int n = 0;
    ListNode* temp = head;
    while(temp != NULL){
        n++;
        temp = temp->next;
    }

    ListNode* firstNode = head;
    for(int i = 1; i < k; i++){
        firstNode = firstNode->next;
    }

    ListNode* lastNode = head;

    for(int i = 1; i <= n - k; i++){
        lastNode = lastNode->next;
    }
    swap(firstNode->val, lastNode->val);

    return head;
}



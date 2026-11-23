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

//  2 3 4 5

ListNode* reverseList(ListNode* head, ListNode* tail){
    ListNode* temp = head;
    ListNode* prev = NULL;
    while(temp != tail){
        ListNode* nextnode = temp->next;

        temp->next = prev;
        prev = temp;
        temp = nextnode;
    }
    return prev;
}


ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(left == right || head == NULL || head->next == NULL){
        return head;
    }

    ListNode* prev = NULL;
    ListNode* temp = head;
    ListNode* leftNode = head;
    for(int i = 1; i < left; i++){
        prev = leftNode;
        leftNode = leftNode->next;
    }

    temp = head;
    for(int i = 1; i < right; i++){
        temp = temp->next;
    }
    ListNode* nextNode = temp->next;

    ListNode* reverseHead = reverseList(leftNode,nextNode);

    if(prev){
        prev->next = reverseHead;
    }
    else{
        head = reverseHead;
    }
    leftNode->next = nextNode;
    return head;   
}




//  1 2 3 4 5
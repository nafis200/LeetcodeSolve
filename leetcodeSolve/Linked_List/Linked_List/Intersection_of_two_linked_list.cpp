
#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;

    ListNode(int val){
        this->val = val;
        next = NULL;
    }
};

 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     ListNode* temp = headA;
     ListNode* temp1 = headB;

     while(temp != temp1){
        if(temp == NULL){
            temp = headB;
            continue;
        }
        if(temp1 == NULL){
            temp1 = headA;
            continue;
        }
        temp = temp->next;
        temp1 = temp1->next;
     }

     return temp;
 }


//  2 6 4
//  1 2

//  first = 4
//  second = 2

//  first = 4
//  second = 2
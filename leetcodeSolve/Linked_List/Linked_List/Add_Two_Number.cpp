// 0 - 3 months:
// Google (40) — Bloomberg (19) — Meta (18) — Amazon (16) — Microsoft (13)

// 0 - 6 months:
// Adobe (3) — Oracle (2) — TikTok (2) — Wix (2) — Cisco (2) — Airbnb (2) — Accenture (2) — Avito (2)

// 6 months ago:
// Apple (52) — Uber (27) — Yahoo (21) — Nvidia (6) — Yandex (6) — TCS (5) — Josh Technology (4) — Tejas Networks (4) — Infosys (3) — IBM (2)

// Problem_Link: https://leetcode.com/problems/add-two-numbers/description/

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

ListNode* CreateList(vector<int>&v1){
    ListNode* head = NULL;
    ListNode* tail = NULL;

    for(int x : v1){
       ListNode* newnode = new ListNode(x);
       if(head == NULL){
         head = newnode;
         tail = newnode;
       }
       else{
          tail->next = newnode;
          tail = newnode;
       }
    }
    return head;
}

 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;
    
    int carry = 0;
    while(l1 && l2){
        int sum = l1->val + l2->val + carry;
        carry = sum / 10;
        sum = sum % 10;
        ListNode* head = new ListNode(sum);
        temp->next = head;
        temp = temp->next;
        l1 = l1->next;
        l2 = l2->next;
    }

    while(l1){
        int sum = l1->val + carry;
         carry = sum / 10;
        sum = sum % 10;
        ListNode* head = new ListNode(sum);
        temp->next = head;
        temp = temp->next;
        l1 = l1->next;
    }

    while(l2){
        int sum = l2->val + carry;
         carry = sum / 10;
        sum = sum % 10;
        ListNode* head = new ListNode(sum);
        temp->next = head;
        temp = temp->next;
        l2 = l2->next;
    }

    if(carry){
        ListNode* head = new ListNode(carry);
        temp->next = head;
        temp = temp->next;
    }

    return dummy->next;
    
 }

  void print(ListNode* head){
      ListNode* temp = head;
      while(temp != NULL){
         cout << temp->val << " ";
         temp = temp->next;
      }
  }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>v1 = {2, 4, 3};
    vector<int>v2 = {5, 6, 4};

    ListNode* l1 = CreateList(v1);
    ListNode* l2 = CreateList(v2);

    ListNode* ans = addTwoNumbers(l1, l2);
    print(ans);

}
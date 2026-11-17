// 0 - 3 months: Google (2)
// 0 - 6 months: Roblox (2)
// 6 months ago: Amazon (8) — Meta (3) — Microsoft (2) — Infosys (2) — Adobe (2) — Salesforce (2) — Workday (2) — BNY Mellon (2)

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

ListNode* CreateNode(vector<int>&nums){
    ListNode* head = NULL;
    ListNode* temp = NULL;
    
    for(auto it : nums){
        ListNode* newnode = new ListNode(it);
        if(head == NULL){
             head = newnode;
             temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;

}

void Print(ListNode* head){
   while(head != NULL){
     cout << head->val << " ";
     head = head->next;
   }
}

ListNode* reverseList(ListNode* head) {
   ListNode* prev = NULL;
   ListNode* cur = head;
   while(cur != NULL){
     ListNode* next = cur->next;
     cur->next = prev;
     prev = cur;
     cur = next;
   }
   return prev;
}

int getDecimalValue(ListNode* head) {
    int ans = 0;
    while(head){
        ans = ans * 2 + head->val;
        head = head->next;
    }
    return ans;
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {1,0,0,1,0,0,1,1,1,0,0,0,0,0,0};
    ListNode* head = CreateNode(nums);


    int ans = getDecimalValue(head);
    cout << ans << "\n";
}
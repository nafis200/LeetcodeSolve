#include <bits/stdc++.h>
using namespace std;

class ListNode {
 public:
  int val;
  ListNode* next;

  ListNode(int x) {
    val = x;
    next = NULL;
  }
};

// [1,4,5],[1,3,4],[2,6]

class cmp{
   public:
    bool operator()(ListNode* a,ListNode* b){
       return a->val > b->val;
   }
};



ListNode* mergeKLists(vector<ListNode*>& lists) {
   priority_queue<ListNode*, vector<ListNode*>,cmp>pq;
   int n = lists.size();
   for(int i = 0; i < n; i++){
      if(lists[i]){
         pq.push(lists[i]);
      }
   }

   ListNode* head = NULL;
   ListNode* temp = NULL;

   while(!pq.empty()){
     ListNode* x = pq.top();
     pq.pop();
     if(head == NULL){
        head = x;
        temp = x;
     }
     else{
         temp->next = x;
         temp = temp->next;
     }
     if(x->next){
        pq.push(x->next);
     }
   }
   return head;
}

int main() {
  vector<vector<int>> arr = {{1, 4, 5}, {1, 3, 4}, {2, 6}};

  vector<ListNode*> lists;

  
  ListNode* head = mergeKLists(lists);



  return 0;
}
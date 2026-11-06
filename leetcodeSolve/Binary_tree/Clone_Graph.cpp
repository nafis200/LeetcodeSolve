

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


// Timeo(v + e) space o(n)


unordered_map<Node*, Node*>mp;

Node* dfs(Node* node){
    if(node == NULL){
        return node;
    }
    if(mp[node]){
        return mp[node];
    }

    Node* cloneNode = new Node(node->val);
    mp[node] = cloneNode;

    for(auto v : node->neighbors){
        Node* neighbourClone = dfs(v);
        cloneNode->neighbors.push_back(neighbourClone);
    }
    return cloneNode;
}

Node* cloneGraph(Node* node) {
   if(node == NULL){
     return node;
   }      

   return dfs(node);
}

void printGraph(Node* node) {
    if (!node) return;

    unordered_set<Node*> vis;
    queue<Node*> q;

    q.push(node);
    vis.insert(node);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        cout << "Node " << cur->val << " -> ";

        for (auto nb : cur->neighbors) {
            cout << nb->val << " ";

            if (!vis.count(nb)) {
                vis.insert(nb);
                q.push(nb);
            }
        }
        cout << "\n";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>>adList = {
        {2, 4},
        {1, 3},
        {2, 4},
        {1, 3}
    };

    int n = adList.size();

    vector<Node*>nodes(n + 2);

    for(int i = 1; i <= n; i++){
        nodes[i] = new Node(i);
    }

    Node* root = cloneGraph(nodes[1]);

    printGraph(root);
}
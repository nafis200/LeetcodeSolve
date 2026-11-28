
#include<bits/stdc++.h>
using namespace std;

bool isValid(string s){
    stack<char>st;
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i] == ')'){
            if(st.empty()){
                return false;
            }
            st.pop();
        }
        else if(s[i] == '('){
             st.push(s[i]);
        }
    }
    if(st.empty()){
        return true;
    }
    return false;
}

vector<string> removeInvalidParentheses(string s) {
    queue<string>q;
    vector<string>ans;
    q.push(s);
    bool ok = false;
    set<string>st;
    st.insert(s);
  
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        if(isValid(x)){
            ans.push_back(x);
            ok = true;
        }
        if(ok){
            continue;
        }
        for(int i = 0; i < x.size(); i++){
            if(x[i] != '(' && x[i] != ')'){
                continue;
            }
            string res = x.substr(0, i) + x.substr(i + 1);
    
            if(st.find(res) == st.end()){
                q.push(res);
                st.insert(res);
            }
        }
     }
     return ans;
 }

 
 

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "(((k()((";
    vector<string>ans = removeInvalidParentheses(s);
   
    for(auto i : ans){
        cout << i << "\n";
    }
}
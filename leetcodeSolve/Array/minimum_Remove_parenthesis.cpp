#include <bits/stdc++.h>
using namespace std;


string minRemoveToMakeValid(string s) {
    int n = s.size();
    vector<bool>remove(n + 1, false);
    stack<int>st;
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            st.push(i);
        }
        else if(s[i] == ')' && st.empty()){
            remove[i] = true;
        }
        else if(s[i] ==')' && s[st.top()] == '('){
             st.pop();
        }
    }
    while(!st.empty()){
        int x = st.top();
        st.pop();
        remove[x] = true;
    }
    string ans = "";
    for(int i = 0; i < n; i++){
        if(!remove[i]){
            ans += s[i];
        }
    }
    return ans;
    
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "lee(t(c)o)de)";
  string ans = minRemoveToMakeValid(s);
  cout << ans << "\n";
}
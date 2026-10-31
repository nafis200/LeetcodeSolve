#include<bits/stdc++.h>
using namespace std;

vector<int>memo;
int n;
unordered_set<string>st;
bool solve(int i, string &s){
    if(i == n){
        return memo[i] = true;
    }
    if(memo[i] != -1){
        return memo[i];
    }
    for(int j = i; j < n; j++){
        string sub = s.substr(i, j - i + 1);
        if(st.find(sub) != st.end()){
            if(solve(j + 1, s)){
                return memo[i] = 1;
            }
        }
    }
    return memo[i] = 0;
}

bool wordBreak(string s, vector<string>& wordDict) {
    st.insert(wordDict.begin(),wordDict.end());
    n = s.size();
    memo.assign(n + 1, -1);
    return solve(0, s);
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "catsandog";
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    bool ans = wordBreak(s, wordDict);
    cout << ans << "\n";
}
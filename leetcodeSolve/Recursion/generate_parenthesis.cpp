
#include<bits/stdc++.h>
using namespace std;

int openBracket, closeBracket;
int sz;
vector<string>ans;

void solve(int i, string &s){
     if(i == sz && openBracket == closeBracket){
         ans.push_back(s);
         return;
    }
    if(openBracket < sz){
        s.push_back('(');
        openBracket++;
        solve(i + 1, s);
        openBracket--;
        s.pop_back();
    }
    if(closeBracket < openBracket){
        s.push_back(')');
        closeBracket++;
        solve(i, s);
        closeBracket--;
        s.pop_back();
    }

}

vector<string> generateParenthesis(int n) {
    sz = n;
    string s = "";
    openBracket = 0;
    closeBracket = 0;
    solve(0, s);
    return ans; 
}
int32_t main(){
   int n = 2;
   
   vector<string>res = generateParenthesis(n);

   for(auto v : res){
     cout << v << "\n";
   }
}
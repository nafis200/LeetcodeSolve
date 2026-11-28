#include <bits/stdc++.h>
using namespace std;



map<char, string> mapping = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                             {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                             {'8', "tuv"}, {'9', "wxyz"}};


int n;
string ans;
vector<string>res;

void Bracktracking(int i, string &digits){
      if(i == n){
         res.push_back(ans);
         return;
      }
      for(auto ch : mapping[digits[i]]){
          ans.push_back(ch);
          Bracktracking(i + 1, digits);
          ans.pop_back();
      }

}

vector<string> letterCombinations(string digits) {
    n = digits.size();
    Bracktracking(0, digits);
    return res;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string digits = "234";
    vector<string>res = letterCombinations(digits);
    for(auto i : res){
        cout << i << " ";
    }
}
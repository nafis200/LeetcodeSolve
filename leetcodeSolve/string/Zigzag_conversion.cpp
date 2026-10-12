
#include<bits/stdc++.h>
using namespace std;
string convert(string s, int numRows) {
    int n = s.size();
    string ans = "";
    int sz = 2 * (numRows) - 2;
    if(numRows == 1){
        return s;
    }

    for(int i = 0; i < numRows; i++){
         int j = i;
         while(j < n){
             ans += s[j];
             if(i != 0 && i != numRows - 1){
                if(j + sz - 2 * i < n){
                    ans += s[j + sz - 2 * i];
                }
             }
             j += sz;
         }
    }
    return ans;
}
int32_t main(){
    string s = "AB";
    int numRows = 1;

    cout << convert(s, numRows) << "\n";
}
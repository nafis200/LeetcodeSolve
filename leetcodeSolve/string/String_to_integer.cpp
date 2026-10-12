
#include<bits/stdc++.h>
using namespace std;
int myAtoi(string s) {
    int sign = 1;
    int n = s.size();
    int i = 0;
    while(i < n && s[i] == ' '){
        i++;
    }
   long long res = 0;
   if(s[i] == '-' || s[i] == '+'){
       if(s[i] == '-'){
          sign = -1;
       }
       i++;
   }
   while(i < n && isdigit(s[i])){
       res = res * 10 + s[i] - '0';
       if(res >= INT_MAX && sign == 1){
          return INT_MAX;
       }
       if(sign == -1 && res * sign <= INT_MIN){
             return INT_MIN;
       }
      i++;
   }
   return res * sign;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = " -042";
    cout << myAtoi(s) << "\n";
}
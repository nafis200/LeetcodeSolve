
#include<bits/stdc++.h>
using namespace std;
// string minWindow(string s, string t) {
//     int n = s.size();
//     unordered_map<char,int>subM;

//     for(auto it : t){
//          subM[it]++;
//     }
//     int required = subM.size();

//     int minLen = INT_MAX;
//     string ans = "";
//     for(int i = 0; i < n; i++){
//         unordered_map<char,int>freq;
//         for(int j = i; j < n; j++){
//              freq[s[j]]++;
//              bool ok = true;

//              for(auto it : subM){
//                 if(it.second > freq[it.first]){
//                     ok = false;
//                     break;
//                 }
//              }
//              if(ok){
//                 if(j - i + 1 < minLen){
//                      minLen = j - i + 1;
//                      ans = s.substr(i, j - i + 1);
//                 }
//              }
//         }
//     }
//     if(minLen == INT_MAX){
//         ans = "";
//     }
//     return ans;
// }

string minWindow(string s, string t) {
    int n = s.size();
    unordered_map<char,int>subM,window;

    for(auto it : t){
         subM[it]++;
    }
    int required = subM.size();

    int minLen = INT_MAX;
    string ans = "";
    int start = 0;
    int form = 0;
    int left = 0;
    for(int i = 0; i < n; i++){
        window[s[i]]++;
        if(subM.count(s[i]) && subM[s[i]] == window[s[i]]){
            form++;
        }
        while(form == required){
            if(i - start + 1 < minLen){
                 minLen = i - start + 1;
                 left = start;
            }
            char ch = s[start];
            window[ch]--;
            if(subM.count(ch) && window[ch] < subM[ch]){
                form--;
            }
            start++;
        }
        
    }
    if(minLen == INT_MAX){
        ans = "";
    }
    else{
        ans = s.substr(left, minLen);
    }
    return ans;
}

int32_t main(){
    string s = "ADOBECODEBANC", t = "ABC";

    cout << minWindow(s, t) << "\n";
}
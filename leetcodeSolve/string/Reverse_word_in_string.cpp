
#include <bits/stdc++.h>
using namespace std;

void reverse(string& s, int left, int right) {
  while (left <= right) {
    swap(s[left], s[right]);
    left++;
    right--;
  }
}

string reverseWords(string s) {
  int i = 0, j = 0;
  int n = s.size();
  reverse(s, 0, n - 1);
  while (j < n) {
    while (j < n && s[j] == ' ') {
      j++;
    }
    while (j < n && s[j] != ' ') {
      s[i] = s[j];
      i++;
      j++;
    }
    while (j < n && s[j] == ' ') {
      j++;
    }
    if (j < n) {
      s[i] = ' ';
      i++;
    }
  }

  s.resize(i);
  i = 0, j = 0, n = s.size();
  while (j < n) {
    while (j < n && s[j] != ' ') {
      j++;
    }
    reverse(s, i, j - 1);
    j++;
    i = j;
  }
  return s;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "  hello   world  ";

  string ans = reverseWords(s);
  cout << ans << "\n";
}
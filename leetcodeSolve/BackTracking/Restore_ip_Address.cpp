

#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> result;

void solve(string& s, int start, vector<string> path) {
  if (start == n) {
    if (path.size() == 4) {
      result.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
    }
    return;
  }
  if (path.size() == 4) {
    return;
  }
  for (int len = 1; len <= 3; len++) {
    if (start + len > n) {
      break;
    }
    string sub = s.substr(start, len);
    if (sub.size() > 1 && sub[0] == '0') {
      continue;
    }

    if (stoi(sub) <= 255) {
      path.push_back(sub);
      solve(s, start + len, path);
      path.pop_back();
    }
  }
}

vector<string> restoreIpAddresses(string s) {
  n = s.size();
  vector<string> path;
  solve(s, 0, path);
  return result;
}
int32_t main() {
  string s = "101023";

  vector<string> ans = restoreIpAddresses(s);
  for (auto i : ans) {
    cout << i << "\n";
  }
}

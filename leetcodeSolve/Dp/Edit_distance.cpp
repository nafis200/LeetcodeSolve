// 0 - 3 months:
// Google (9) — Microsoft (3) — Meta (2) — Bloomberg (2)

// 0 - 6 months:
// Amazon (5) — LinkedIn (5) — Cisco (3) — Zoho (2)

// 6 months ago:
// TikTok (9) — Flipkart (5) — Infosys (2) — Deloitte (2) — TCS (2) — Adobe (2)
// — Oracle (2) — Walmart Labs (2) — EPAM Systems (2) — Visa (2)

// https://leetcode.com/problems/edit-distance/description/

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> memo;

string s, t;

int dp(int i, int j) {
  if (i == n) {
    return m - j;
  }
  if (j == m) {
    return n - i;
  }

  if (memo[i][j] != -1) {
    return memo[i][j];
  }

  int ans = 1e9;
  if (s[i] == t[j]) {
    ans = min(ans, dp(i + 1, j + 1));
  } else {
    ans = min(ans, dp(i + 1, j + 1) + 1);
    ans = min(ans, dp(i, j + 1) + 1);
    ans = min(ans, dp(i + 1, j) + 1);
  }
  return memo[i][j] = ans;
}

int minDistance(string word1, string word2) {
  n = word1.size();
  m = word2.size();
  s = word1;
  t = word2;
  memo.assign(n + 1, vector<int>(m + 1, -1));
  return dp(0, 0);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string word1 = "horse", word2 = "ros";
  int ans = minDistance(word1, word2);
  cout << ans << "\n";
}
#include "bits/stdc++.h"

using namespace std;

void solve(const string &s) {
  int n = s.size();
  vector<int> z(n);
  vector<int> total(n);
  int l = 0, r = 0;
  for(int i = 1; i < n; ++i) {
    if (i < r) {
      z[i] = min(r-i, z[i-l]);
    }
    while (i + z[i] < n && s[z[i]] == s[i+z[i]])
      ++z[i];
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
    total[z[i]] ++;
  }
  for(int i = 1; i < n; ++i) {
    total[i] += total[i-1];
  }
  vector<pair<int, int>> ans;
  for(int i = n-1; i >= 0; --i) {
    if (z[i] == n - i) {
      ans.emplace_back(z[i], n - total[z[i]-1]);
    }
  }
  ans.emplace_back(n, 1);
  cout << ans.size() << '\n';
  for(int i = 0; i < ans.size(); ++i) {
    cout << ans[i].first << ' ' << ans[i].second << '\n';
  }
}

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  solve(s);
  return 0;
}

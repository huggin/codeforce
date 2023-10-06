
#include <bits/stdc++.h>
using namespace std;

string s, t;
int n, k;

void solve() {
  cin >> n >> k;
  cin >> s >> t;
  if (n >= 6) {
    int cnt[26] = {0};
    for (int i = 0; i < n; i++) {
      cnt[s[i] - 'a']++;
      cnt[t[i] - 'a']--;
    }
    cout << (count(cnt, cnt + 26, 0) == 26 ? "YES" : "NO") << '\n';
    return;
  }
  queue<string> q;
  set<string> visited;
  q.push(s);
  visited.insert(s);
  auto add = [&](string &s, int i, int j) {
    if (i >= 0 && j < n) {
      swap(s[i], s[j]);
      if (!visited.count(s)) {
        q.push(s);
        visited.insert(s);
      }
      swap(s[i], s[j]);
    }
  };

  while (!q.empty()) {
    s = q.front();
    q.pop();
    for (int i = 0; i < n; i++) {
      add(s, i, i + k);
      add(s, i, i + k + 1);
    }
  }
  cout << (visited.count(t) ? "YES" : "NO") << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}

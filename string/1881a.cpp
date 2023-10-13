
#include <bits/stdc++.h>
using namespace std;

int n, m;
string s, t;

void solve() {
  cin >> n >> m;
  cin >> s >> t;
  int ans = 0;
  while (s.size() < t.size()) {
    ans++;
    s = s + s;
  }
  if (s.find(t) != string::npos) {
    cout << ans << '\n';
    return;
  }
  s = s + s;
  if (s.find(t) != string::npos) {
    cout << ans + 1 << '\n';
    return;
  }
  cout << -1 << '\n';
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

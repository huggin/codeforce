
#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
  cin >> n;
  int s, e;
  cin >> s >> e;
  bool found = false;
  int ans = s;
  int time = e;
  for (int i = 1; i < n; i++) {
    cin >> s >> e;
    if (s >= ans && e >= time) {
      found = true;
    }
  }
  cout << (found ? -1 : ans) << '\n';
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

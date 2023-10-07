
#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void solve() {
  cin >> n;
  cin >> s;
  int cnt = 0;
  for (int i = 1; i < n - 1; i++) {
    if (s[i - 1] == s[i + 1]) {
      cnt++;
    }
  }
  cout << n - 1 - cnt << '\n';
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

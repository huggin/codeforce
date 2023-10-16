#include <bits/stdc++.h>
using namespace std;

int n;
string s[1000];

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int ans = 0;
  for (int i = 0; i < n / 2; i++) {
    for (int j = i; j < n - 1 - i; j++) {
      char ma = s[i][j];
      ma = max(ma, s[j][n - 1 - i]);
      ma = max(ma, s[n - 1 - i][n - 1 - j]);
      ma = max(ma, s[n - 1 - j][i]);

      ans += ma - s[i][j];
      ans += ma - s[j][n - 1 - i];
      ans += ma - s[n - 1 - i][n - 1 - j];
      ans += ma - s[n - 1 - j][i];
    }
  }
  cout << ans << '\n';
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

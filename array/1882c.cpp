
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
int n, t;
int a[MAXN];
long long suf[MAXN + 1];

void solve() {
  cin >> n;
  long long s = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  suf[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = suf[i + 1] + max(a[i], 0);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      ans = max(ans, a[i] + suf[i + 1]);
    } else {
      ans = max(ans, suf[i + 1]);
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

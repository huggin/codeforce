
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300000;
int n;
int a[MAXN], b[MAXN];

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  long long ta = 0, tb = 0;
  long long ma = 1e9 + 1, mb = 1e9 + 1;
  for (int i = 0; i < n; i++) {
    ta += a[i];
    ma = min(ma, static_cast<long long>(a[i]));
    tb += b[i];
    mb = min(mb, static_cast<long long>(b[i]));
  }
  cout << min(ta + mb * n, tb + ma * n) << '\n';
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

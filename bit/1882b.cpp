
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;
int n, k, t;
long long a[MAXN];

void solve() {
  cin >> n;
  long long s = 0;
  for (int i = 0; i < n; i++) {
    cin >> k;
    a[i] = 0;
    for (int j = 0; j < k; j++) {
      cin >> t;
      a[i] |= 1LL << (t - 1);
    }
    s |= a[i];
  }
  int ans = 0;
  for (int i = 0; i < 50; i++) {
    long long t = 0;
    for (int j = 0; j < n; j++) {
      if (!(a[j] & (1LL << i))) {
        t |= a[j];
      }
    }
    if (t != s)
      ans = max(ans, __builtin_popcountll(t));
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

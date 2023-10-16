
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;
int n;
int a[MAXN];

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 1;
  for (int i = 0; i < n; i++) {
    if (a[i] == ans) {
      ans++;
    }
    ans++;
  }
  cout << ans - 1 << '\n';
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

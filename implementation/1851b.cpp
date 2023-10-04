
#include <bits/stdc++.h>
using namespace std;

int a[200000];
int b[200000];
int n, m, k, h;

void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  memcpy(b, a, sizeof(a));
  sort(a, a + n);
  bool flag = true;
  for (int i = 0; i < n; ++i) {
    if ((a[i] - b[i]) % 2) {
      flag = false;
      break;
    }
  }
  if (flag) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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


#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
int a[mxN];
int n, k;

void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (k == 1) {
    cout << "YES\n";
    return;
  }
  int color = a[0];
  int cnt = 1;
  int left = -1;
  for (int i = 1; i < n; ++i) {
    if (color == a[i]) {
      if (++cnt == k) {
        left = i;
        break;
      }
    }
  }
  if (left != -1 && a[0] == a[n - 1]) {
    cout << "YES\n";
    return;
  }
  color = a[n - 1];
  cnt = 1;
  int right = -1;
  for (int i = n - 2; i >= 0; --i) {
    if (color == a[i]) {
      if (++cnt == k) {
        right = i;
        break;
      }
    }
  }
  if (left != -1 && right != -1 && left <= right) {
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

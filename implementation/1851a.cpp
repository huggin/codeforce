
#include <bits/stdc++.h>
using namespace std;

int a[50];
int n, m, k, h;

int solve() {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == h)
      continue;
    int d = abs(a[i] - h) % k;
    int b = abs(a[i] - h) / k;
    if (d == 0 && b < m) {
      ++ans;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    cin >> n >> m >> k >> h;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cout << solve() << '\n';
  }

  return 0;
}

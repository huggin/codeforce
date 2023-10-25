
#include <bits/stdc++.h>
using namespace std;

int k, x;

int total(int n) {
  int ans = 0;
  while (n > 0) {
    ans += n % 10;
    n /= 10;
  }
  return ans;
}

void solve() {
  cin >> x >> k;
  for (int i = x;; i++) {
    if (total(i) % k == 0) {
      cout << i << '\n';
      return;
    }
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

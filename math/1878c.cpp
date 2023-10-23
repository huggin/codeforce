
#include <bits/stdc++.h>
using namespace std;

long long n, k, x;

void solve() {
  cin >> n >> k >> x;
  long long a = (1 + k) * k / 2;
  long long b = (n + n + 1 - k) * k / 2;
  cout << (a <= x && x <= b ? "YES\n" : "NO\n");
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

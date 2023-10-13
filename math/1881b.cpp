
#include <bits/stdc++.h>
using namespace std;

int a, b, c;

void solve() {
  cin >> a >> b >> c;
  long long d = std::gcd(std::gcd(a, b), c);
  long long e = a / d + b / d + c / d;
  cout << (e <= 6 ? "YES" : "NO") << '\n';
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

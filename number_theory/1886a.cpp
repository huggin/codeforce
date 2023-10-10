
#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
  cin >> n;
  if (n <= 6) {
    cout << "NO\n";
  } else {
    if ((n - 3) % 3 != 0 && n - 3 != 1 && n - 3 != 2) {
      cout << "YES\n";
      cout << 1 << ' ' << 2 << ' ' << n - 1 - 2 << '\n';
    } else if ((n - 5) % 3 != 0 && n - 5 != 1 && n - 5 != 4) {
      cout << "YES\n";
      cout << 1 << ' ' << 4 << ' ' << n - 1 - 4 << '\n';
    } else if ((n - 6) % 3 != 0 && n - 6 != 2 && n - 6 != 4) {
      cout << "YES\n";
      cout << 2 << ' ' << 4 << ' ' << n - 2 - 4 << '\n';
    } else {
      cout << "NO\n";
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

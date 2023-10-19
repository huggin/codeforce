
#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
  cin >> n;
  int a;
  unordered_map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> a;
    for (int j = 2; j * j <= a; j++) {
      while (a % j == 0) {
        cnt[j]++;
        a /= j;
      }
    }
    if (a != 1) {
      cnt[a]++;
    }
  }
  for (auto [k, v] : cnt) {
    if (v % n != 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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

#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
long long a[mxN];
int n, k;

void solve() {
  cin >> n;
  vector<int> v(n + 1);
  long long out = -1;
  long long prev = 0;
  for (int i = 0; i < n - 1; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; ++i) {
    long long curr = a[i] - prev;
    prev = a[i];
    if (curr == 0) {
      cout << "NO\n";
      return;
    }
    if (curr > n) {
      if (out != -1) {
        cout << "NO\n";
        return;
      } else {
        out = curr;
        continue;
      }
    }
    if (v[curr] != 0) {
      if (out != -1) {
        cout << "NO\n";
        return;
      } else {
        out = curr;
      }
    }
    v[curr] += 1;
  }
  if (out == -1) {
    cout << "YES\n";
    return;
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (v[i] == 0) {
      cnt += i;
    }
  }
  if (cnt == out) {
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

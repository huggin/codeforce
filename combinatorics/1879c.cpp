
#include <bits/stdc++.h>
using namespace std;

string s;
const int MOD = 998244353;

void solve() {
  cin >> s;
  int n = s.size();
  vector<long long> fact(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = fact[i - 1] * i % MOD;
  }
  char c = '2';
  int cnt = 1;
  int removed = 0;
  long long ans = 1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == c) {
      cnt++;
    } else {
      ans = ans * cnt % MOD;
      removed += cnt - 1;
      cnt = 1;
    }
    c = s[i];
  }
  ans = ans * cnt % MOD;
  removed += cnt - 1;

  cout << removed << ' ' << ans * fact[removed] % MOD << '\n';
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

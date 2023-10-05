
#include <bits/stdc++.h>
using namespace std;

string s, t;
int n, k;

void solve() {
  cin >> n >> k;
  cin >> s >> t;
  int cnt[26] = {0};
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (i < k && n - 1 - i < k) {
      ok &= s[i] == t[i];
    } else {
      cnt[s[i] - 'a']++;
      cnt[t[i] - 'a']--;
    }
  }
  if (ok && count(cnt, cnt + 26, 0) == 26) {
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

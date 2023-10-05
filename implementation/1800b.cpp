
#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

void solve() {
  cin >> n >> k;
  cin >> s;
  int cnt[52] = {0};
  for (int i = 0; i < n; i++) {
    if (isupper(s[i])) {
      cnt[s[i] - 'A']++;
    } else {
      cnt[s[i] - 'a' + 26]++;
    }
  }
  int ans = 0;
  for (int i = 0; i < 26; i++) {
    ans += min(cnt[i], cnt[i + 26]);
    int more = abs(cnt[i] - cnt[i + 26]);
    if (more >= 2 * k) {
      ans += k;
      k = 0;
    } else {
      ans += more / 2;
      k -= more / 2;
    }
  }
  cout << ans << '\n';
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

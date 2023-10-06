
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
int n;
string s;
int a[MAXN], b[MAXN], c[MAXN];
unordered_map<int, int> m;

long long calc(int j) {
  m.clear();
  long long ans = 0;
  int mask = ((1 << 26) - 1) ^ (1 << j);
  for (int i = 0; i < n; i++) {
    if ((b[i] & (1 << j)) == 0) {
      ans += m[mask ^ a[i]];
      m[a[i]]++;
    }
  }
  return ans;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    a[i] = 0, b[i] = 0;

    for (char c : s) {
      a[i] ^= 1 << (c - 'a');
      b[i] |= 1 << (c - 'a');
    }
  }
  long long ans = 0;
  for (int i = 0; i < 26; i++) {
    ans += calc(i);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  solve();
  return 0;
}

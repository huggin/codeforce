
#include <bits/stdc++.h>
using namespace std;

string s;
long long n;

void solve() {
  cin >> s >> n;
  string st;
  --n;
  int m = s.size();
  int curr_len = m;
  int cnt = 0;
  while (n >= curr_len) {
    n -= curr_len;
    cnt++;
    curr_len--;
  }
  for (int i = 0; i < m; i++) {
    while (cnt > 0 && !st.empty() && st.back() > s[i]) {
      --cnt;
      st.pop_back();
    }
    if (cnt == 0) {
      if (n < st.size()) {
        cout << st[n];
      } else {
        cout << s[n - st.size() + i];
      }
      return;
    } else {
      st.push_back(s[i]);
    }
  }
  cout << st[n];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  cout << '\n';

  return 0;
}

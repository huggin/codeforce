
#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void solve() {
  cin >> n;
  cin >> s;
  string t = "meow";
  string m;
  for (int i = 0; i < n; i++) {
    if (m.size() != 0 && m[m.size() - 1] == tolower(s[i])) {
      continue;
    } else {
      m.push_back(tolower(s[i]));
    }
  }
  if (m == t) {
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

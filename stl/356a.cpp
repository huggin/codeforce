#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  set<int> alive;
  int k;
  for (int i = 0; i < n; i++) {
    alive.insert(i);
  }
  int l, r, x;
  vector<int> ans(n);
  for (int i = 0; i < m; i++) {
    cin >> l >> r >> x;
    l--, r--, x--;
    vector<int> remove;
    auto it = alive.lower_bound(l);
    while (it != alive.end()) {
      if (*it > r) {
        break;
      }
      if (*it != x) {
        ans[*it] = x + 1;
        remove.push_back(*it);
      }
      it++;
    }
    for (auto i : remove) {
      alive.erase(i);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i];
    if (i != n - 1) {
      cout << ' ';
    }
  }
  cout << '\n';

  return 0;
}

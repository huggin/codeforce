
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
int u, v;
map<int, bool> ok;
int last;
map<vector<int>, int> mem;

int dfs(int u, int p) {
  vector<int> children;
  for (int v : g[u]) {
    if (v == p)
      continue;
    children.push_back(dfs(v, u));
  }
  sort(children.begin(), children.end());
  if (mem.count(children)) {
    return mem[children];
  }
  int curr = last++;
  unordered_map<int, int> cnt;
  for (int c : children) {
    cnt[c]++;
  }
  int odd = 0, pos = -1;
  for (auto [k, v] : cnt) {
    if (v & 1) {
      odd++;
      pos = k;
    }
  }
  if (odd >= 2) {
    ok[curr] = false;
  } else if (odd == 1) {
    ok[curr] = ok[pos];
  } else {
    ok[curr] = true;
  }
  mem[children] = curr;
  return curr;
}

void solve() {
  cin >> n;
  last = 0;
  mem.clear();
  ok.clear();
  g.clear();
  g.assign(n, vector<int>{});
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cout << (ok[dfs(0, 0)] ? "YES" : "NO") << '\n';
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

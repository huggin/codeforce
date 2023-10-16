
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
int n, t;
vector<int> g[MAXN];
int a[MAXN];
int c[MAXN];

int dfs(int u, int p, long long &ans) {
  int cnt = 1;
  for (auto v : g[u]) {
    if (v == p)
      continue;
    int nsub = dfs(v, u, ans);
    c[v] = nsub;
    ans += nsub * static_cast<long long>(a[v] ^ a[u]);
    cnt += nsub;
  }
  return cnt;
}

void dfs2(int u, int p, vector<long long> &ans) {
  for (int v : g[u]) {
    if (v == p)
      continue;
    ans[v] = ans[u] + (n - 2 * c[v]) * static_cast<long long>(a[u] ^ a[v]);
    dfs2(v, u, ans);
  }
}

void solve() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    g[i].clear();
    c[i] = 0;
    cin >> a[i];
  }
  int e1, e2;
  for (int i = 0; i < n - 1; i++) {
    cin >> e1 >> e2;
    g[e1 - 1].push_back(e2 - 1);
    g[e2 - 1].push_back(e1 - 1);
  }
  vector<long long> ans(n);
  long long cnt = 0;
  dfs(0, -1, cnt);
  ans[0] = cnt;
  dfs2(0, -1, ans);

  for (int i = 0; i < n; i++) {
    cout << ans[i];
    if (i != n - 1) {
      cout << ' ';
    }
  }
  cout << '\n';
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

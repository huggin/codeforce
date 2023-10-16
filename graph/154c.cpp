#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1000001;
int n, m;
long long g[MAXN];

const int p = 7;

void solve() {
  cin >> n >> m;
  memset(g, 0, sizeof(g));
  vector<long long> p_pow(n);
  p_pow[0] = 1;
  for (int i = 1; i < n; i++) {
    p_pow[i] = p_pow[i - 1] * p;
  }
  int a, b;
  vector<pair<int, int>> edges;
  vector<long long> cnt;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    g[a - 1] = g[a - 1] + p_pow[b - 1];
    g[b - 1] = g[b - 1] + p_pow[a - 1];

    edges.emplace_back(a - 1, b - 1);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    cnt.push_back(g[i]);
  }
  sort(cnt.begin(), cnt.end());
  long long prev = -1;
  for (int i = 0; i < n; i++) {
    if (cnt[i] != prev) {
      int j = upper_bound(cnt.begin(), cnt.end(), cnt[i]) - cnt.begin();
      ans += 1LL * (j - i) * (j - i - 1) / 2;
    }
    prev = cnt[i];
  }

  for (auto e : edges) {
    if (g[e.first] + p_pow[e.first] == g[e.second] + p_pow[e.second]) {
      ans++;
    }
  }
  cout << ans << '\n';
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}

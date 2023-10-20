
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
int n, m, t;
vector<int> g[MAXN];
int marked[MAXN];

void solve() {
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    cin >> marked[i];
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  int a, b;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }
  if (m == 1) {
    cout << "0\n";
    return;
  }
  queue<int> q;
  q.push(marked[0] - 1);
  q.push(0);
  vector<int> dist(n, -1);
  dist[marked[0] - 1] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    int d = q.front();
    q.pop();
    for (int v : g[u]) {
      if (dist[v] == -1) {
        dist[v] = d + 1;
        q.push(v);
        q.push(d + 1);
      }
    }
  }
  int md = 0;
  int v2 = -1;
  for (int i = 1; i < m; i++) {
    if (dist[marked[i] - 1] > md) {
      v2 = marked[i] - 1;
      md = dist[v2];
    }
  }
  dist.assign(n, -1);
  dist[v2] = 0;
  q.push(v2);
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    int d = q.front();
    q.pop();
    for (int v : g[u]) {
      if (dist[v] == -1) {
        dist[v] = d + 1;
        q.push(v);
        q.push(d + 1);
      }
    }
  }
  int d = 0;
  for (int i = 0; i < m; i++) {
    d = max(d, dist[marked[i] - 1]);
  }
  cout << (d + 1) / 2 << '\n';
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

#include <bits/stdc++.h>

using namespace std;

const int MaxN = 300000;
const int M = 998244353;
long long t[MaxN * 4];
int n, m;
string s;
int cnt[MaxN];

void merge(int v) { t[v] = (t[2 * v] * t[2 * v + 1]) % M; }

void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = cnt[tl];
    return;
  }
  int tm = tl + (tr - tl) / 2;
  build(v * 2, tl, tm);
  build(v * 2 + 1, tm + 1, tr);
  merge(v);
}

void update(int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    t[v] = val;
  } else {
    int tm = tl + (tr - tl) / 2;
    if (pos <= tm) {
      update(v * 2, tl, tm, pos, val);
    } else {
      update(v * 2 + 1, tm + 1, tr, pos, val);
    }
    merge(v);
  }
}

long long query(int v, int tl, int tr, int l, int r) {
  if (l > r) {
    return 1;
  }
  if (l == tl && tr == r) {
    return t[v];
  }
  int tm = tl + (tr - tl) / 2;
  return query(v * 2, tl, tm, l, min(tm, r)) *
         query(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r) % M;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  cin >> s;

  for (int i = 0; i < n - 1; i++) {
    cnt[n - 2 - i] = s[n - 2 - i] == '>' or s[n - 2 - i] == '<' ? 1 : n - 2 - i;
  }
  build(1, 0, n - 2);

  cout << t[1] << '\n';

  int j;
  char c;
  for (int i = 0; i < m; i++) {
    cin >> j >> c;
    --j;
    cnt[j] = c == '?' ? j : 1;
    update(1, 0, n - 2, j, cnt[j]);
    cout << t[1] << '\n';
  }

  return 0;
}

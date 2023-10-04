#include <bits/stdc++.h>

using namespace std;

const int MxN = 131072;
int a[MxN];
int t[MxN * 4];

int build(int a[], int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = a[tl];
    return 0;
  }
  int tm = tl + (tr - tl) / 2;
  int left = build(a, v * 2, tl, tm);
  int right = build(a, v * 2 + 1, tm + 1, tr);
  if (left % 2 == 0) {
    t[v] = t[v * 2] | t[v * 2 + 1];
  } else {
    t[v] = t[v * 2] ^ t[v * 2 + 1];
  }
  return left + 1;
}

int update(int a[], int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    a[pos] = val;
    t[v] = val;
    return 0;
  } else {
    int tm = tl + (tr - tl) / 2;
    int level = -1;
    if (pos <= tm) {
      level = update(a, v * 2, tl, tm, pos, val);
    } else {
      level = update(a, v * 2 + 1, tm + 1, tr, pos, val);
    }
    if (level % 2 == 0) {
      t[v] = t[v * 2] | t[v * 2 + 1];
    } else {
      t[v] = t[v * 2] ^ t[v * 2 + 1];
    }
    return level + 1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < (1 << n); i++) {
    cin >> a[i];
  }
  build(a, 1, 0, (1 << n) - 1);
  int p, b;
  for (int i = 0; i < m; i++) {
    cin >> p >> b;
    update(a, 1, 0, (1 << n) - 1, p - 1, b);
    cout << t[1] << '\n';
  }

  return 0;
}

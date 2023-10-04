#include <bits/stdc++.h>
#include <climits>

using namespace std;

const int MaxN = 200000;
const long long INF = LONG_LONG_MAX;
int a[MaxN];
long long t[MaxN * 4];
long long lazy[MaxN * 4];

void push(int v) {
  t[v * 2] += lazy[v];
  lazy[v * 2] += lazy[v];
  t[v * 2 + 1] += lazy[v];
  lazy[v * 2 + 1] += lazy[v];
  lazy[v] = 0;
}

void build(int a[], int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = a[tl];
    return;
  }
  int tm = tl + (tr - tl) / 2;
  build(a, v * 2, tl, tm);
  build(a, v * 2 + 1, tm + 1, tr);
  t[v] = min(t[v * 2], t[v * 2 + 1]);
}

long long query(int a[], int v, int tl, int tr, int l, int r) {
  if (l > r) {
    return INF;
  }
  if (tl == l && tr == r) {
    return t[v];
  }
  push(v);
  int tm = (tl + tr) / 2;
  long long left = query(a, v * 2, tl, tm, l, min(tm, r));
  long long right = query(a, v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
  return min(left, right);
}

void update(int v, int tl, int tr, int l, int r, int val) {
  if (l > r)
    return;
  if (l == tl && r == tr) {
    t[v] += val;
    lazy[v] += val;
  } else {
    push(v);
    int tm = tl + (tr - tl) / 2;
    update(v * 2, tl, tm, l, min(r, tm), val);
    update(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r, val);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  memset(lazy, 0, sizeof(lazy));
  build(a, 1, 0, n - 1);
  cin >> m;
  string line;
  int l, r, val, num;
  std::getline(std::cin, line);
  for (int i = 0; i < m; i++) {
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int count = 0;
    while (iss >> num) {
      if (count == 0) {
        l = num;
      } else if (count == 1) {
        r = num;
      } else if (count == 2) {
        val = num;
      }
      count++;
    }
    if (count == 2) {
      if (l <= r) {
        cout << query(a, 1, 0, n - 1, l, r) << '\n';
      } else {
        if (l == r + 1) {
          cout << query(a, 1, 0, n - 1, 0, n - 1) << '\n';
        } else {
          int left = query(a, 1, 0, n - 1, 0, r);
          int right = query(a, 1, 0, n - 1, l, n - 1);
          cout << min(left, right) << '\n';
        }
      }
    } else {
      if (l <= r) {
        update(1, 0, n - 1, l, r, val);
      } else {
        if (l == r + 1) {
          update(1, 0, n - 1, 0, n - 1, val);
        } else {
          update(1, 0, n - 1, 0, r, val);
          update(1, 0, n - 1, l, n - 1, val);
        }
      }
    }
  }

  return 0;
}

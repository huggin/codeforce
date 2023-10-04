#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MaxN = 100000;
ll a[MaxN];
int n, m;

struct Node {
  ll sum;
  int idx;

  Node() = default;
  Node(ll s, int i) : sum(s), idx(i) {}
};

Node t[MaxN * 4];

Node merge(const Node &v1, const Node &v2) {
  Node node = Node(v1.sum + v2.sum, v1.idx);
  if (v1.idx == -1 || v2.idx != -1 && a[v1.idx] < a[v2.idx]) {
    node.idx = v2.idx;
  }
  return node;
}

void build(ll a[], int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = Node(a[tl], tl);
    return;
  }
  int tm = tl + (tr - tl) / 2;
  build(a, v * 2, tl, tm);
  build(a, v * 2 + 1, tm + 1, tr);
  t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

Node query(int v, int tl, int tr, int l, int r) {
  if (l > r) {
    return Node(0, -1);
  }
  if (tl == l && tr == r) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  Node left = query(v * 2, tl, tm, l, min(tm, r));
  Node right = query(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
  return merge(left, right);
}

void update(int v, int tl, int tr, int pos, ll val) {
  if (tl == tr) {
    t[v] = Node(val, tl);
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos <= tm) {
    update(v * 2, tl, tm, pos, val);
  } else {
    update(v * 2 + 1, tm + 1, tr, pos, val);
  }
  t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, t;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  build(a, 1, 0, n - 1);
  int l, r, k, x, op;
  for (int i = 0; i < m; i++) {
    cin >> op;
    if (op == 1) {
      cin >> l >> r;
      auto node = query(1, 0, n - 1, l - 1, r - 1);
      cout << node.sum << '\n';
    } else if (op == 2) {
      cin >> l >> r >> x;
      while (true) {
        auto node = query(1, 0, n - 1, l - 1, r - 1);
        if (a[node.idx] >= x) {
          a[node.idx] %= x;
          update(1, 0, n - 1, node.idx, a[node.idx]);
        } else {
          break;
        }
      }
    } else {
      cin >> k >> x;
      a[k - 1] = x;
      update(1, 0, n - 1, k - 1, x);
    }
  }

  return 0;
}

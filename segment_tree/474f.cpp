#include <bits/stdc++.h>

using namespace std;

const int MaxN = 100000;
int a[MaxN];

struct Node {
  int min;
  int gcd;
  int cnt;

  Node() : min(0), gcd(0), cnt(0) {}
  Node(int v, int g, int c) : min(v), gcd(g), cnt(c) {}
};

Node t[MaxN * 4];

Node merge(Node v1, Node v2) {
  if (v1.min == 0) {
    return v2;
  }
  if (v2.min == 0) {
    return v1;
  }
  int mi = min(v1.min, v2.min);
  int gcd = std::gcd(v1.gcd, v2.gcd);
  int cnt = 0;
  if (v1.min == mi) {
    cnt += v1.cnt;
  }
  if (v2.min == mi) {
    cnt += v2.cnt;
  }
  return Node(mi, gcd, cnt);
}

void build(int a[], int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = Node(a[tl], a[tl], 1);
    return;
  }
  int tm = tl + (tr - tl) / 2;
  build(a, v * 2, tl, tm);
  build(a, v * 2 + 1, tm + 1, tr);
  t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

Node query(int v, int tl, int tr, int l, int r) {
  if (l > r) {
    return Node();
  }
  if (tl == l && tr == r) {
    return t[v];
  }
  Node ans;
  int tm = tl + (tr - tl) / 2;
  Node left = query(v * 2, tl, tm, l, min(tm, r));
  Node right = query(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
  return merge(left, right);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, t;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  build(a, 1, 0, n - 1);
  cin >> t;
  int l, r;
  for (int i = 0; i < t; i++) {
    cin >> l >> r;
    Node node = query(1, 0, n - 1, l - 1, r - 1);
    if (node.min != node.gcd) {
      cout << r - l + 1 << '\n';
    } else {
      cout << r - l + 1 - node.cnt << '\n';
    }
  }

  return 0;
}

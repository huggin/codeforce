#include <bits/stdc++.h>

using namespace std;

const int MaxN = 100000;
long long a[MaxN];
long long h[MaxN];
long long x[MaxN * 2];
long long y[MaxN * 2];
int t1[MaxN * 8][2];
int t2[MaxN * 8][2];

void merge(long long a[], int t[][2], int v) {
  if (a[t[v * 2][0]] > a[t[v * 2 + 1][0]]) {
    t[v][0] = t[v * 2][0];
    if (t[v * 2][1] == -1 or a[t[v * 2][1]] < a[t[v * 2 + 1][0]]) {
      t[v][1] = t[v * 2 + 1][0];
    } else {
      t[v][1] = t[v * 2][1];
    }
  } else {
    t[v][0] = t[v * 2 + 1][0];
    if (t[v * 2 + 1][1] == -1 or a[t[v * 2 + 1][1]] < a[t[v * 2][0]]) {
      t[v][1] = t[v * 2][0];
    } else {
      t[v][1] = t[v * 2 + 1][1];
    }
  }
}

vector<int> merge(long long a[], int t[][2], const vector<int> &left,
                  const vector<int> &right) {
  if (left[0] == -1) {
    return right;
  } else if (right[0] == -1) {
    return left;
  }
  vector<int> ans(2);
  if (a[left[0]] > a[right[0]]) {
    ans[0] = left[0];
    if (left[1] == -1 or a[left[1]] < a[right[0]]) {
      ans[1] = right[0];
    } else {
      ans[1] = left[1];
    }
  } else {
    ans[0] = right[0];
    if (right[1] == -1 or a[right[1]] < a[left[0]]) {
      ans[1] = left[0];
    } else {
      ans[1] = right[1];
    }
  }
  return ans;
}

void build(long long a[], int t[][2], int v, int tl, int tr) {
  if (tl == tr) {
    t[v][0] = tl;
    t[v][1] = -1;
    return;
  }
  int tm = tl + (tr - tl) / 2;
  build(a, t, v * 2, tl, tm);
  build(a, t, v * 2 + 1, tm + 1, tr);
  merge(a, t, v);
}

vector<int> query(long long a[], int t[][2], int v, int tl, int tr, int l,
                  int r) {
  if (l > r) {
    return vector<int>(2, -1);
  }
  if (l == tl && r == tr) {
    return vector<int>{t[v][0], t[v][1]};
  }
  int tm = (tl + tr) / 2;

  vector<int> left = query(a, t, v * 2, tl, tm, l, min(r, tm));
  vector<int> right = query(a, t, v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
  return merge(a, t, left, right);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  long long dist = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (i < n) {
      x[i] = dist + 2 * h[i];
      y[i] = 2 * h[i] - dist;
      dist += a[i];
    } else {
      x[i] = dist + 2 * h[i - n];
      y[i] = 2 * h[i - n] - dist;
      dist += a[i - n];
    }
  }

  build(x, t1, 1, 0, 2 * n - 1);
  build(y, t2, 1, 0, 2 * n - 1);
  int l, r, b, e;
  for (int i = 0; i < m; i++) {
    cin >> l >> r;
    l--, r--;
    if (l <= r) {
      vector<int> left = query(x, t1, 1, 0, 2 * n - 1, r + 1, n - 1 + l);
      vector<int> right = query(y, t2, 1, 0, 2 * n - 1, r + 1, n - 1 + l);
      if (left[0] != right[0]) {
        cout << x[left[0]] + y[right[0]] << '\n';
      } else {
        cout << max(x[left[0]] + y[right[1]], x[left[1]] + y[right[0]]) << '\n';
      }
    } else {
      vector<int> left = query(x, t1, 1, 0, 2 * n - 1, r + 1, l - 1);
      vector<int> right = query(y, t2, 1, 0, 2 * n - 1, r + 1, l - 1);
      if (left[0] != right[0]) {
        cout << x[left[0]] + y[right[0]] << '\n';
      } else {
        cout << max(x[left[0]] + y[right[1]], x[left[1]] + y[right[0]]) << '\n';
      }
    }
  }

  return 0;
}

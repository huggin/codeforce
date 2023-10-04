#include <bits/stdc++.h>

using namespace std;

const int MaxN = 100000;
int t[MaxN * 4][26];

void merge(int v) {
  for (int i = 0; i < 26; i++) {
    t[v][i] = t[2 * v][i] | t[2 * v + 1][i];
  }
}

void build(const string &s, int v, int tl, int tr) {
  if (tl == tr) {
    t[v][s[tl] - 'a'] = 1;
    return;
  }
  int tm = tl + (tr - tl) / 2;
  build(s, v * 2, tl, tm);
  build(s, v * 2 + 1, tm + 1, tr);
  merge(v);
}

void update(string &s, int v, int tl, int tr, int pos, char val) {
  if (tl == tr) {
    t[v][s[pos] - 'a'] = 0;
    s[pos] = val;
    t[v][val - 'a'] = 1;
  } else {
    int tm = tl + (tr - tl) / 2;
    if (pos <= tm) {
      update(s, v * 2, tl, tm, pos, val);
    } else {
      update(s, v * 2 + 1, tm + 1, tr, pos, val);
    }
    merge(v);
  }
}

vector<int> query(int v, int tl, int tr, int l, int r) {
  if (l > r) {
    return vector<int>(26, 0);
  }
  if (l == tl && tr == r) {
    return vector<int>(t[v], t[v] + 26);
  }
  vector<int> ans(26);
  int tm = tl + (tr - tl) / 2;
  vector<int> left = query(v * 2, tl, tm, l, min(tm, r));
  vector<int> right = query(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
  for (int i = 0; i < 26; i++) {
    ans[i] = left[i] | right[i];
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  build(s, 1, 0, s.size() - 1);

  int m;
  cin >> m;
  int ops;
  for (int i = 0; i < m; i++) {
    cin >> ops;
    if (ops == 1) {
      int pos;
      char c;
      cin >> pos >> c;
      update(s, 1, 0, s.size() - 1, pos - 1, c);
    } else {
      int l, r;
      cin >> l >> r;
      vector<int> res = query(1, 0, s.size() - 1, l - 1, r - 1);
      cout << count(res.begin(), res.end(), 1) << '\n';
    }
  }

  return 0;
}

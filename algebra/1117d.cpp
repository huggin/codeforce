#include <bits/stdc++.h>

using namespace std;

const int M = 1000000007;
long long a[101][101];
long long v[101][101];
long long res[101][101];

void matmul(long long a[][101], long long b[][101], int m) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      res[i][j] = 0;
      for (int k = 0; k < m; k++) {
        res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % M;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      b[i][j] = res[i][j];
    }
  }
}

int power(long long a[][101], long long x, int m) {
  memset(v, 0, sizeof(v));
  for (int i = 0; i < m; i++) {
    v[i][i] = 1;
  }
  while (x > 0) {
    if (x & 1) {
      matmul(a, v, m);
    }
    matmul(a, a, m);
    x >>= 1;
  }
  return v[0][0];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  if (n < m) {
    cout << 1 << '\n';
  } else {
    memset(a, 0, sizeof(a));
    a[0][0] = 1;
    a[0][m - 1] = 1;
    for (int i = 1; i < m; i++) {
      a[i][i - 1] = 1;
    }
    cout << power(a, n, m) << '\n';
  }
}

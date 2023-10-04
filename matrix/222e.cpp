#include <bits/stdc++.h>
#include <cctype>

using namespace std;

const int M = 1000000007;
long long a[52][52];
long long v[52][52];
long long res[52][52];

void matmul(long long a[][52], long long b[][52], int m) {
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

int power(long long a[][52], long long x, int m) {
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
  int ans = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++)
      ans = (ans + v[i][j]) % M;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = 1;
    }
  }
  string s;
  for (int i = 0; i < k; i++) {
    cin >> s;
    int i1, i2;
    if (isupper(s[0])) {
      i1 = s[0] - 'A' + 26;
    } else {
      i1 = s[0] - 'a';
    }
    if (isupper(s[1])) {
      i2 = s[1] - 'A' + 26;
    } else {
      i2 = s[1] - 'a';
    }
    a[i1][i2] = 0;
  }

  cout << power(a, n - 1, m) << '\n';
}

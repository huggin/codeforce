#include <bits/stdc++.h>

using namespace std;

const int M = 1000000007;
long long a[101][101];
long long v[101][101];
long long res[101][101];
long long dp[100];

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

void power(long long a[][101], long long x, int m) {
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
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, l, m;
  cin >> n >> l >> m;
  memset(dp, 0, sizeof(dp));
  int s[n], b[n], w[n];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    s[i] %= m;
    dp[s[i]]++;
  }
  memset(a, 0, sizeof(a));
  int cnt[m];
  memset(cnt, 0, sizeof(int) * m);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
    w[i] %= m;
    cnt[w[i]]++;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      a[i][(i - j + m) % m] = cnt[j];
    }
  }
  power(a, l - 2, m);

  int dp2[m];
  for (int i = 0; i < m; i++) {
    dp2[i] = 0;
    for (int j = 0; j < m; j++) {
      dp2[i] = (dp2[i] + dp[j] * v[i][j]) % M;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    b[i] %= m;
  }
  for (int i = 0; i < n; i++) {
    ans = (ans + dp2[(m + m - w[i] - b[i]) % m]) % M;
  }
  cout << ans << '\n';
}


#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
int n;
string s;
int a[MAXN];
int dp[MAXN];

int solve(int k) {
  if (k == n) {
    return 0;
  }
  if (dp[k] != -1) {
    return dp[k];
  }
  int &ans = dp[k];
  ans = 1 + solve(k + 1);
  if (a[k] + k < n) {
    ans = min(ans, solve(a[k] + k + 1));
  }
  return ans;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(0) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}

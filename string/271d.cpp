#include "bits/stdc++.h"

using namespace std;

string s, t;
int good[26];
int k, n;

const int p = 31;
const int M = 1e9 + 9;
vector<long long> p_pow(1501);

void solve() {
  cin >> s >> t;
  cin >> k;
  n = s.size();
  memset(good, 0, sizeof(good));
  for (int i = 0; i < t.size(); i++) {
    good[i] = t[i] - '0';
  }
  p_pow[0] = 1;
  for (int i = 1; i < n; i++) {
    p_pow[i] = p_pow[i - 1] * p % M;
  }

  vector<long long> h(n + 1, 0);
  for (int i = 0; i < n; i++) {
    h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % M;
  }
  vector<int> bad(n + 1, 0);
  for (int i = 0; i < n; i++) {
    bad[i + 1] = bad[i] + (good[s[i] - 'a'] == 0);
  }
  int cnt = 0;
  for (int l = 1; l <= n; l++) {
    unordered_set<long long> us;
    for (int i = 0; i <= n - l; i++) {
      if (bad[i + l] - bad[i] > k)
        continue;

      long long cur_h = (h[i + l] + M - h[i]) % M;
      cur_h = (cur_h * p_pow[n - i - 1]) % M;
      us.insert(cur_h);
    }
    cnt += us.size();
  }
  cout << cnt << '\n';
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}


#include <bits/stdc++.h>
using namespace std;

int n;
const int MaxN = 200000;
int a;

void solve() {
  priority_queue<int> pq;
  long long ans = 0;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a == 0) {
      if (!pq.empty()) {
        ans += pq.top();
        pq.pop();
      }
    } else {
      pq.push(a);
    }
  }
  cout << ans << '\n';
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

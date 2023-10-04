#include <bits/stdc++.h>

using namespace std;

const int MaxN = 100000;
int bit[MaxN + 1];
int a[MaxN + 1];
const int MN = 10001;
bool lucky[MN];

bool ok(int k) {
  while (k) {
    if (!(k % 10 == 4 || k % 10 == 7))
      return false;
    k /= 10;
  }
  return true;
}

void update(int x, int d) {
  for (int i = x + 1; i <= MaxN; i += i & -i)
    bit[i] += d;
}

int sum(int x) {
  int ans = 0;
  for (int i = x + 1; i > 0; i -= i & -i)
    ans += bit[i];
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  memset(bit, 0, sizeof(bit));
  for (int i = 1; i < MN; i++) {
    lucky[i] = ok(i);
  }
  int n, m;
  cin >> n >> m;
  for (int j = 0; j < n; j++) {
    cin >> a[j];
    if (lucky[a[j]]) {
      update(j, 1);
    }
  }
  string s;
  int x, y, v;
  for (int i = 0; i < m; i++) {
    cin >> s;
    if (s == "count") {
      cin >> x >> y;
      cout << sum(y - 1) - sum(x - 2) << '\n';
    } else {
      cin >> x >> y >> v;
      for (int j = x; j <= y; j++) {
        if (lucky[a[j - 1]])
          update(j - 1, -1);
        a[j - 1] += v;
        if (lucky[a[j - 1]])
          update(j - 1, 1);
      }
    }
  }
  return 0;
}

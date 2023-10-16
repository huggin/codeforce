
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

const double EPS = 1e-9;

double dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void solve() {
  double px, py, ax, ay, bx, by;

  cin >> px >> py >> ax >> ay >> bx >> by;
  double w1 = dist(ax, ay, px, py);
  double w2 = dist(bx, by, px, py);
  double w3 = dist(ax, ay, 0, 0);
  double w4 = dist(bx, by, 0, 0);
  double w = dist(ax, ay, bx, by) / 2;
  double ans = 1e9;
  ans = min(ans, max(w1, w3));
  ans = min(ans, max(w2, w4));
  ans = min(ans, max({w1, w4, w}));
  ans = min(ans, max({w2, w3, w}));
  cout << std::setprecision(10) << fixed << ans << '\n';
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

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  cout << 4 * 2 * 3 * static_cast<long long>(pow(4, n - 3)) +
              (n - 3) * 4 * 3 * 3 * static_cast<long long>(pow(4, n - 4))
       << '\n';
  return 0;
}

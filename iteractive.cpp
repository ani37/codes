
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int h;
    cin >> h;
    auto f1 = [&](int v) {
      cout << 1 << " " << v << endl;
      int ret;
      cin >> ret;
      return ret;
    };

    auto f2 = [&](int v, int d) {
      cout << 2 << " " << v << " " << d << endl;
      int ret;
      cin >> ret;
      return ret;
    };

    auto f3 = [&](int v) {
      cout << 3 << " " << v << endl;
      int ret;
      cin >> ret;
    };

    int v = f2(1, h);
    while (true) {
      int d = f1(v);
      if (d == 0) {
        f3(v);
        break;
      }
      v = f2(v, d);
      if (d == 2) {
        f3(v);
        break;
      }

    }
  }
  return 0;
}

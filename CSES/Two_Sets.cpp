// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  06.10.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition
// section)-----------------------------------------
#define Dbg(x) cout << #x << " = " << x << '\n';
#define int long long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
void solve(void) {
  int n;
  cin >> n;
  if (n < 3)
    cout << "NO\n";
  else {
    int sum = (n * (n + 1)) / 2;
    if (sum & 1)
      cout << "NO\n";
    else {
      cout << "YES\n";
      int l = 1, r = n;
      sum /= 2;
      set<int> st1;
      while (sum) {
        if (sum >= r) {
          st1.insert(r);
          sum -= r;
          r--;
        }
        if (sum >= l) {
          st1.insert(l);
          sum -= l;
          l++;
        }
      }
      cout << st1.size() << '\n';
      for (auto &it : st1)
        cout << it << ' ';
      cout << '\n';
      cout << (r - l + 1) << '\n';
      while (l <= r) {
        cout << l << ' ';
        l++;
      }
      cout << '\n';
    }
  }
}
//-----------------------------------------------------------------------------------------
signed main() {
  // cout << fixed << showpoint << setprecision(10);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test = 1, T;
  // cin >> test;
  for (T = 1; T <= test; T++) {
    // cout << "Case " << T << ": ";
    solve();
  }
  return 0;
}
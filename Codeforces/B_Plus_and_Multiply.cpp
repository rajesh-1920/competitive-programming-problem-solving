// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  07.10.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition
// section)-----------------------------------------
#define Dbg(x) cout << #x << " = " << x << '\n'
#define int long long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void) {
  int n, a, b;
  cin >> n >> a >> b;
  if (a == 1) {
    if (n == 1)
      cout << "YES\n";
    else {
      n--;
      if (n % b == 0)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  } else {
    int t = 1;
    while (n >= t) {
      if ((n - t) % b == 0) {
        cout << "YES\n";
        return;
      }
      t *= a;
    }
    cout << "NO\n";
  }
}
//-----------------------------------------------------------------------------------------
signed main() {
  // cout << fixed << showpoint << setprecision(10);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test = 1, T;
  cin >> test;
  for (T = 1; T <= test; T++) {
    // cout << "Case " << T << ": ";
    solve();
  }
  return 0;
}
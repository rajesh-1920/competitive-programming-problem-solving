// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  09.10.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition
//section)-----------------------------------------
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
  string s;
  int ans = 0;
  for (int i = 0; i < 10; i++) {
    cin >> s;
    for (int j = 0; j < 10; j++)
      if (s[j] == 'X')
        if (j == 0 || i == 0 || j == 9 || i == 9)
          ans++;
        else if (i == 1 || j == 1 || i == 8 || j == 8)
          ans += 2;
        else if (i == 2 || j == 2 || i == 7 || j == 7)
          ans += 3;
        else if (i == 3 || j == 3 || i == 6 || j == 6)
          ans += 4;
        else
          ans += 5;
  }
  cout << ans << '\n';
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
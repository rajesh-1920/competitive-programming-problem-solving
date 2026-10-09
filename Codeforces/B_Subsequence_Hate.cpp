// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  09.10.2026

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
  string s;
  cin >> s;
  vector<int> zr(s.size(), 0), on(s.size(), 0);
  for (int i = 0; i < s.size(); i++) {
    (s[i] == '1') ? on[i]++ : zr[i]++;
    if (i)
      on[i] += on[i - 1], zr[i] += zr[i - 1];
  }
  int ans = inf, z = 0, o = 0;
  for (int i = s.size() - 1; i >= 0; i--) {
    ans = min(ans, z + on[i]);
    ans = min(ans, o + zr[i]);
    (s[i] == '1') ? o++ : z++;
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
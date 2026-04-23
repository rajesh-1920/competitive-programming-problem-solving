// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  04.03.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
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
int ok(int l, int r, int lev)
{
  if (l == r)
    return 0;
  int m = (l + r) / 2;
  if (lev == 0)
    return max(m - l, r - m);
  return max(ok(l, m, lev - 1), ok(m + 1, r, lev - 1));
}
void solve(void)
{
  int n, q;
  cin >> n >> q;
  if (q >= 40)
  {
    cout << 0 << '\n';
    return;
  }
  cout << ok(1, n, q) << '\n';
}
//-----------------------------------------------------------------------------------------
signed main()
{
  // cout << fixed << showpoint << setprecision(10);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test = 1, T;
  cin >> test;
  for (T = 1; T <= test; T++)
  {
    // cout << "Case #" << T << ": ";
    solve();
  }
  return 0;
}
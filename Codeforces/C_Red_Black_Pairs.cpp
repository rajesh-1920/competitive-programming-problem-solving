// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  16.06.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
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
void solve(void)
{
  int n;
  string a, b;
  cin >> n >> a >> b;
  int ans = 0;
  for (int i = 0; i < n;)
  {
    if ((i + 1 < n) && (a[i] == b[i] && a[i + 1] == b[i + 1]))
      i += 2;
    else if ((i + 1 < n) && (a[i] == a[i + 1] && b[i] == b[i + 1]))
      i += 2;
    else
      ans += (a[i] != b[i]), i++;
  }
  cout << ans << '\n';
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
    // cout << "Case " << T << ": ";
    solve();
  }
  return 0;
}
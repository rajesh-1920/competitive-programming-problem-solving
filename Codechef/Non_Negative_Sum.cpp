// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  14.04.2026

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
void solve(void)
{
  int n, ans = 0, s = 0;
  cin >> n;
  vector<int> v;
  while (n--)
  {
    int x;
    cin >> x;
    if (x >= 0)
      ans++, s += x;
    else
      v.push_back(x);
  }
  sort(rall(v));
  for (auto &it : v)
    if (-it <= s)
      ans++, s += it;
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
    // cout << "Case #" << T << ": ";
    solve();
  }
  return 0;
}
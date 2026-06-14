// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  14.06.2026

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
  int n, mn = INT_MAX, ans = inf;
  cin >> n;
  vector<int> v(n);
  for (auto &it : v)
    cin >> it, mn = min(mn, it);
  if (mn == 1)
    mn++;
  while (mn > 1)
  {
    int cnt = 0;
    for (auto &it : v)
    {
      int x = it;
      while (true)
      {
        if (x == mn)
          break;
        if (x < mn)
        {
          cnt = ((x & 1) && x + 1 == mn) ? cnt + 1 : inf;
          break;
        }
        cnt++;
        if (x & 1)
          x++;
        else
          x >>= 1;
      }
      if (cnt == inf)
        break;
    }
    ans = min(cnt, ans);
    if (mn & 1)
      mn++;
    else
      mn >>= 1;
  }
  int cnt = 0;
  for (auto &it : v)
  {
    int x = it;
    while (true)
    {
      if (x == mn)
        break;
      if (x < mn)
      {
        cnt = ((x & 1) && x + 1 == mn) ? cnt + 1 : inf;
        break;
      }
      cnt++;
      if (x & 1)
        x++;
      else
        x >>= 1;
    }
    if (cnt == inf)
      break;
  }
  ans = min(cnt, ans);
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
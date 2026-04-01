// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  01.04.2026

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
  int n, mm;
  cin >> n >> mm;
  vector<int> v(n);
  for (auto &it : v)
    cin >> it;
  int ans = 0, l = 0, r = 1e8 + 7;
  while (l <= r)
  {
    int m = (l + r) / 2, fl = 1;
    priority_queue<int> pq;
    for (auto &it : v)
      pq.push(it);
    for (int i = 0; i < mm; i++)
    {
      if (pq.empty())
      {
        fl = 0;
        break;
      }
      if (pq.top() < m)
      {
        fl = 0;
        break;
      }
      int x = pq.top();
      pq.pop();
      pq.push(x - m);
    }
    if (fl)
      ans = m, l = m + 1;
    else
      r = m - 1;
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
  // cin >> test;
  for (T = 1; T <= test; T++)
  {
    // cout << "Case #" << T << ": ";
    solve();
  }
  return 0;
}
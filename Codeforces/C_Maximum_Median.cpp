// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  27.05.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
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
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (auto &it : v)
    cin >> it;
  sort(all(v));
  map<int, int> mp;
  for (int i = n / 2; i < n; i++)
    mp[v[i]]++;
  while (k && mp.size() > 1)
  {
    auto [x, y] = *mp.begin();
    mp.erase(mp.begin());
    auto [xx, yy] = *mp.begin();
    mp.erase(mp.begin());
    if (k >= (xx - x) * y)
    {
      k -= (xx - x) * y;
      mp[xx] = y + yy;
    }
    else if (k >= y)
    {
      int t = k / y;
      k %= y;
      mp[x + t] = y;
      mp[xx] = yy;
    }
    else
    {
      mp[x] = 1;
      k = 0;
    }
  }
  cout << (*mp.begin()).fi + k / (*mp.begin()).sc << '\n';
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
    // cout << "Case " << T << ": ";
    solve();
  }
  return 0;
}
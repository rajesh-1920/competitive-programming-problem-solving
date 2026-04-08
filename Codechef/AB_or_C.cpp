// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  08.04.2026

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

//------------------------------(solve)----------------------------------------------------
void solve(void)
{
  int n;
  cin >> n;
  vector<pair<int, int>> v;

  for (int i = 0, x, y, z; i < n; i++)
  {
    cin >> x >> y >> z;
    v.push_back({x, i});
    v.push_back({y, i});
    v.push_back({z, i});
  }

  sort(all(v));
  map<int, int> mp;
  int l = 0;                 
  int ans = LLONG_MAX;       
  for (int r = 0; r < (int)v.size(); r++)
  {
    mp[v[r].sc]++;
    while ((int)mp.size() == n)
    {
      ans = min(ans, v[r].fi - v[l].fi);
      mp[v[l].sc]--;
      if (mp[v[l].sc] == 0)
        mp.erase(v[l].sc);

      l++;
    }
  }
  cout << ans << '\n';
}

//-----------------------------------------------------------------------------------------
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int test = 1;
  cin >> test;

  while (test--)
  {
    solve();
  }

  return 0;
}
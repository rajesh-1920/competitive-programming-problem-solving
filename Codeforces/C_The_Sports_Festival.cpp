// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  05.06.2026

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
  cin >> n;
  vector<int> v;
  map<int, int> mp;
  for (int i = 0, x; i < n; i++)
  {
    cin >> x;
    mp[x]++;
  }
  while (mp.size() > 1)
  {
    int x = (*mp.begin()).fi;
    for (int i = 0; i < mp[x]; i++)
      v.push_back(x);
    x = (*(--mp.end())).fi;
    for (int i = 0; i < mp[x]; i++)
      v.push_back(x);
    mp.erase(--mp.end()), mp.erase(mp.begin());
  }
  for (auto it : mp)
    for (int i = 0; i < it.sc; i++)
      v.push_back(it.fi);
  reverse(all(v));
  int ans = 0, mn = v.front(), mx = v.front();
  for (auto &it : v)
  {
    // cout << it << ' ';
    mx = max(mx, it), mn = min(mn, it);
    ans += mx - mn;
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
    // cout << "Case " << T << ": ";
    solve();
  }
  return 0;
}
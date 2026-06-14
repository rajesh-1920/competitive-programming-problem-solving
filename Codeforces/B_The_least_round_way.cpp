// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  07.06.2026

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
pair<int, int> ok(int i, int j, vector<vector<pair<int, int>>> &v)
{
  if (i == v.size() && j == v.size())
    return {0, 0};
  pair<int, int> ans = {MOD, MOD};
  if (i < v.size() && j < v.size())
  {
    pair<int, int> temp = ok(i + 1, j, v);
    ans = min(ans, {temp.fi + v[i][j].fi, temp.sc + v[i][j].sc});
    temp = ok(i, j + 1, v);
    ans = min(ans, {temp.fi + v[i][j].fi, temp.sc + v[i][j].sc});
  }
  return ans;
}
void solve(void)
{
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> v(n, vector<pair<int, int>>(n, {0, 0}));
  for (int i = 0; i < n; i++)
    for (int j = 0, x; j < n; j++)
    {
      cin >> x;
      if (x == 0)
      {
        v[i][j] = {1, 1};
        continue;
      }
      int cnt = 0;
      while (x % 2 == 0)
        x /= 2, cnt++;
      v[i][j].fi = cnt;
      cnt = 0;
      while (x % 5 == 0)
        x /= 5, cnt++;
      v[i][j].sc = cnt;
    }
  cout << ok(0, 0, v).fi << ' ' << ok(0, 0, v).sc << '\n';
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
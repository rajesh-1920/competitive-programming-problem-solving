// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  13.05.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
#define fi first
#define sc second
#define int long long int

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int MOD = 1e18 + 7;
const int N = 1e7 + 1;

//-----------------------------------------------------------------------------------------
int val(string &s)
{
  int rt = 0;
  for (int i = 0; i < s.size(); i++)
  {
    rt = (s[i] - '0') + rt * 10;
  }
  return rt;
}
void solve(void)
{
  string a;
  int d;
  cin >> a >> d;
  vector<int> v(d);
  int ffl = val(a);

  for (auto &x : v)
    cin >> x;
  sort(all(v));
  reverse(all(a));
  while (!a.empty() && ((a.back() - '0' == v[0]) || (a.back() - '0' == v[1])))
    a.pop_back();
  reverse(all(a));
  int ans = MOD, vl = val(a);

  if (vl == 0 && ffl != 0)
    ans = 0;
  if (a.size() > 1)
  {
    int fl = ((a[0] - '0') * 10) + (a[1] - '0');
    for (int i = 0; i < 4; i++)
    {
      int x = (i & 1) ? v[0] : v[1];
      int tt = i / 2;
      int y = (tt & 1) ? v[0] : v[1];
      int c1 = x * 10 + y;
      if (c1 < fl)
        for (int i = 2; i < a.size(); i++)
          c1 = c1 * 10 + v[1];
      else
        for (int i = 2; i < a.size(); i++)
          c1 = c1 * 10 + v[0];
      ans = min(ans, 1LL * abs(vl - c1));
    }
    int c1 = 0;
    for (int i = 1; i < a.size(); i++)
      c1 = c1 * 10 + v[1];
    ans = min(ans, 1LL * abs(vl - c1));

    c1 = 0;
    for (int i = 0; i <= a.size(); i++)
      c1 = c1 * 10 + v[0];
    ans = min(ans, 1LL * abs(vl - c1));
    c1 = v[1];
    for (int i = 0; i < a.size(); i++)
      c1 = c1 * 10 + v[0];
    ans = min(ans, 1LL * abs(vl - c1));
    c1 = v[1];
    for (int i = 1; i < a.size(); i++)
      c1 = c1 * 10 + v[0];
    ans = min(ans, 1LL * abs(vl - c1));
    c1 = v[1];
    for (int i = 0; i <= a.size(); i++)
      c1 = c1 * 10 + v[0];
    ans = min(ans, 1LL * abs(vl - c1));
  }
  else
  {
    int c1 = v[1];
    for (int i = 0; i < a.size(); i++)
      c1 = c1 * 10 + v[0];
    ans = min(ans, 1LL * abs(vl - c1));
    ans = min(ans, 1LL * abs(vl - v[0]));
    ans = min(ans, 1LL * abs(vl - v[1]));
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
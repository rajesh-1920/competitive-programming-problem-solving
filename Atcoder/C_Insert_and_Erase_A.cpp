// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  28.02.2026

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
  string s, t;
  cin >> s >> t;
  string s1 = "", t1 = "";
  for (auto &it : s)
    if (it != 'A')
      s1.push_back(it);
  for (auto &it : t)
    if (it != 'A')
      t1.push_back(it);
  if (t1.size() != s1.size())
  {
    cout << -1;
    return;
  }
  for (int i = 0; i < t1.size(); i++)
    if (s1[i] != t1[i])
    {
      cout << -1;
      return;
    }
  int ans = 0, l = 0, r = 0;
  while (true)
  {
    if (l < s.size() && r < t.size())
    {
      if (s[l] == t[r])
        l++, r++;
      else
      {
        ans++;
        if (s[l] == 'A')
          l++;
        else
          r++;
      }
    }
    else if (l < s.size() || r < t.size())
      ans++, l++, r++;
    else
      break;
  }
  cout << ans;
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
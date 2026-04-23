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
  string s;
  cin >> s;
  set<int> a, b, c;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == 'A')
      a.insert(i);
    else if (s[i] == 'B')
      b.insert(i);
    else
      c.insert(i);
  int ans = 0;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == 'A')
    {
      a.erase(i);
      if (!b.empty() && !c.empty())
      {
        int t = *b.begin();
        b.erase(b.begin());
        if (c.lower_bound(t + 1) != c.end())
        {
          ans++;
          c.erase(c.lower_bound(t + 1));
        }
        else
          break;
      }
      else
        break;
    }
    else if (s[i] == 'B')
    {
      b.insert(i);
      b.erase(i);
    }
    else
    {
      c.insert(i);
      c.erase(i);
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
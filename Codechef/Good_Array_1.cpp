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
map<pair<int, vector<int>>, int> mp;
int ok(int i, vector<int> &v)
{
  if (mp.count({i, v}))
    return mp[{i, v}];
  bool fl = true;
  for (int j = 0; j < v.size(); j++)
  {
    map<int, int> mp;
    multiset<int> st;
    for (int ii = j; ii < v.size(); ii++)
    {
      // return -1;
      if (v[ii] == -1)
        break;
      if (st.find(mp[v[ii]]) != st.end())
        st.erase(st.find(mp[v[ii]]));
      mp[v[ii]]++;
      st.insert(mp[v[ii]]);
      if (*st.begin() > 1)
      {
        fl = false;
        break;
      }
    }
    if (!fl)
      break;
  }
  if (fl)
    return 0;
  if (i == v.size())
    return MOD;
  int ans = ok(i + 1, v);
  int temp = v[i];
  v[i] = -1;
  ans = min(ans, ok(i + 1, v) + 1);
  v[i] = temp;
  return mp[{i, v}] = ans;
}
void solve(void)
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &it : v)
    cin >> it;
  mp.clear();
  cout << ok(0, v) << '\n';
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
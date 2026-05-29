// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  30.05.2026

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
  int n;
  string s;
  cin >> n >> s;
  vector<int> last(26, -1), bad(n, 0);
  set<int> temp;
  int mn = n + 5, l = 0, r = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (last[s[i] - 'a'] != -1 && mn > i - last[s[i] - 'a'])
      mn = i - last[s[i] - 'a'], l = last[s[i] - 'a'], r = i;
    last[s[i] - 'a'] = i;
    temp.insert(i);
  }
  while (mn <= n)
  {
    temp.erase(l), temp.erase(r);
    if (temp.lower_bound(l) != temp.end() && (*temp.lower_bound(l)) < r)
    {
      cout << "NO\n";
      return;
    }

    queue<int> q;
    auto it = temp.lower_bound(l);
    while (it != temp.end() && *it < r)
      q.push(*it), it++;
    while (!q.empty())
    {
      int i = q.front();
      temp.erase(i), temp.insert(i - 1), bad[i - 1] = bad[i] + 1;
      q.pop();
    }
    it = temp.lower_bound(r);
    while (it != temp.end())
      q.push(*it), it++;
    while (!q.empty())
    {
      int i = q.front();
      temp.erase(i), temp.insert(i - 2), bad[i - 2] = bad[i] + 2;
      q.pop();
    }

    mn = n + 5;
    vector<int> lat(26, -1);
    for (auto &i : temp)
    {
      if (lat[s[i + bad[i]] - 'a'] != -1 && mn > i - lat[s[i + bad[i]] - 'a'])
        mn = i - lat[s[i + bad[i]] - 'a'], l = lat[s[i + bad[i]] - 'a'], r = i;
      lat[s[i + bad[i]] - 'a'] = i;
    }
  }
  if (temp.empty())
    cout << "YES\n";
  else
    cout << "NO\n";
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
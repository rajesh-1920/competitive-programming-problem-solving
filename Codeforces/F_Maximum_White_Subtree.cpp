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
void solve(void)
{
  int n;
  cin >> n;
  vector<int> v(n), ans(n, -1), deg(n, 0), par(n, -1);
  vector<vector<int>> g(n);
  for (auto &it : v)
    cin >> it;
  for (int i = 1, x, y; i < n; i++)
  {
    cin >> x >> y;
    x--, y--;
    deg[x]++, deg[y]++;
    g[x].push_back(y), g[y].push_back(x);
  }
  queue<int> q;
  q.push(0);
  while (!q.empty())
  {
    int t = q.front();
    q.pop();
    for (auto &it : g[t])
      if (it && par[it] == -1)
        q.push(it), par[it] = t;
  }
  for (int i = 0; i < n; i++)
    if (deg[i] == 1)
    {
      q.push(i);
      if (v[i] == 1)
        ans[i] = 1;
      deg[i]--;
    }
  while (!q.empty())
  {
    int t = q.front();
    q.pop();
    if (par[t] != -1)
    {
      Dbg(t);
      ans[par[t]] = max(ans[par[t]], ans[t] + ans[par[t]] + v[par[t]]);
    }
    for (auto &it : g[t])
    {
      deg[it]--;
      if (deg[it] == 1)
        q.push(it);
    }
  }
  for (auto &it : ans)
    cout << it << ' ';
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
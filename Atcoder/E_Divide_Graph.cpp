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
const int MOD = 998244353;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
void init(int &a, vector<int> &par, vector<int> &sz)
{
  par[a] = a, sz[a] = 1;
}
int parent(int a, vector<int> &par)
{
  if (par[a] == a)
    return a;
  return par[a] = parent(par[a], par);
}
bool _union(int a, int b, vector<int> &par, vector<int> &sz)
{
  int pa = parent(a, par), pb = parent(b, par);
  if (sz[pa] < sz[pb])
    swap(pa, pb);
  if (pa != pb)
  {
    par[pb] = pa, sz[pa] += sz[pb];
    return false;
  }
  return true;
}
void dfs(int n, vector<set<int>> &v, vector<int> &vis)
{
  vis[n] = 1;
  for (auto &it : v[n])
    if (!vis[it])
      dfs(it, v, vis);
}
int modpow(int a)
{
  int ans = 1, x = 2;
  while (a)
  {
    if (a & 1)
      ans = (ans * x) % MOD;
    a >>= 1;
    x = (x * x) % MOD;
  }
  return ans;
}
void solve(void)
{
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges(m);
  for (auto &it : edges)
    cin >> it.fi >> it.sc;
  vector<set<int>> v(n);
  vector<int> par(n), sz(n), hate, vis(n, 0);
  for (int i = 0; i < n; i++)
    init(i, par, sz);
  int mn = m - 1;
  for (int i = m - 1; i >= 0; i--)
  {
    int a = edges[i].fi - 1, b = edges[i].sc - 1;
    if (_union(a, b, par, sz))
      hate.push_back(i);
    else
    {
      mn = i;
      v[a].insert(b);
      v[b].insert(a);
    }
  }
  v[edges[mn].fi - 1].erase(edges[mn].sc - 1);
  v[edges[mn].sc - 1].erase(edges[mn].fi - 1);
  dfs(edges[mn].fi - 1, v, vis);
  int ans = modpow(mn + 1) % MOD;
  for (auto &it : hate)
  {
    int a = edges[it].fi - 1, b = edges[it].sc - 1;
    if (vis[a] != vis[b])
      ans = (ans + modpow(it + 1)) % MOD;
  }
  cout << ans % MOD << '\n';
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
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
int parent(int a, vector<int> &par)
{
  if (par[a] == a)
    return a;
  return par[a] = parent(par[a], par);
}
void solve(void)
{
  int n;
  cin >> n;
  vector<pair<int, int>> v(n - 1), todel;
  vector<int> par(n, n - 1), sz(n, 1);
  for (int i = 0; i < n - 1; i++)
  {
    cin >> v[i].fi >> v[i].sc;
    v[i].fi--, v[i].sc--;
    par[i] = i;
  }
  for (auto &it : v)
  {
    int a = parent(it.fi, par), b = parent(it.sc, par);
    if (a == b)
      todel.push_back(it);
    else
    {
      if (sz[a] < sz[b])
        swap(a, b);
      sz[a] += sz[b];
      par[b] = parent(a, par);
    }
  }
  cout << todel.size() << '\n';
  for (int i = 1; i < n; i++)
  {
    int a = parent(i, par), b = parent(0, par);
    if (a != b)
    {
      cout << todel.back().fi + 1 << ' ' << todel.back().sc + 1 << ' ' << 1 << ' ' << i + 1 << '\n';
      todel.pop_back();
      if (sz[a] < sz[b])
        swap(a, b);
      sz[a] += sz[b];
      par[b] = parent(a, par);
    }
  }
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
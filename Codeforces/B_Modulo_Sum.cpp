// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  05.06.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define Dbg(x) cout << #x << " = " << x << '\n'
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e3 + 10;
//-----------------------------------------------------------------------------------------
int m;
vector<int> cnt(N, 0), v;
int dp[N][N][2];
int ok(int i, int s, int fl)
{
  if (s % m == 0 && fl)
    return 1;
  if (i == v.size())
    return 0;
  if (dp[i][s][fl] != -1)
    return dp[i][s][fl];
  int ans = ok(i + 1, s, fl);
  for (int j = 1; j <= cnt[v[i]]; j++)
    if (ok(i + 1, (s + v[i] * j) % m, 1))
    {
      ans = 1;
      break;
    }
  return dp[i][s][fl] = ans;
}
void solve(void)
{
  int n;
  cin >> n >> m;
  memset(dp, -1, sizeof(dp));
  for (int i = 0, x; i < n; i++)
  {
    cin >> x;
    x %= m;
    if (cnt[x] == 0)
      v.push_back(x);
    cnt[x]++;
    if (cnt[x] >= m || v.size() == m)
    {
      cout << "YES\n";
      return;
    }
  }
  if (ok(0, 0, 0))
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
  // cin >> test;
  for (T = 1; T <= test; T++)
  {
    // cout << "Case " << T << ": ";
    solve();
  }
  return 0;
}
// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  03.06.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define Dbg(x) cout << #x << " = " << x << '\n';
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
vector<int> v(N);
int dp[105][26][26][26];
int ok(int n, int p1, int p2, int p3, int &sz)
{
  if (p1 == p2 && p2 == p3)
    return N;
  if (n >= sz)
    return 0;
  if (dp[n][p1][p2][p3] != -1)
    return dp[n][p1][p2][p3];
  int ans = N;
  for (int i = max(0, v[n] - 5); i < min(26, v[n] + 6); i++)
    ans = min(ans, ok(n + 1, p2, p3, i, sz) + (v[n] != i));
  return dp[n][p1][p2][p3] = ans;
}
void solve(void)
{
  int n;
  string s;
  cin >> n >> s;
  if (n < 3)
  {
    cout << "0\n";
    return;
  }
  for (int i = 0; i < n; i++)
    v[i] = s[i] - 'a';

  int ans = n;
  memset(dp, -1, sizeof(dp));
  for (int i = max(0, v[0] - 5); i < min(26, v[0] + 6); i++)
    for (int j = max(0, v[1] - 5); j < min(26, v[1] + 6); j++)
      for (int k = max(0, v[2] - 5); k < min(26, v[2] + 6); k++)
      {
        ans = min(ans, ok(3, i, j, k, n) + (v[0] != i) + (v[1] != j) + (v[2] != k));
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
    // cout << "Case #" << T << ": ";
    solve();
  }
  return 0;
}
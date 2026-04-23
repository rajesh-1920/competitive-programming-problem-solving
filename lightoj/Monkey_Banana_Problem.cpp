// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  17.04.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
// #define int long long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;

//------------------------------------------(solve)------------------------------------------
int ok(int i, int j, int &n, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
  if (i >= 2 * n - 1 || j < 0)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];
  int ans = ok(i + 1, j, n, grid, dp);
  if (i < n - 1)
    ans = max(ans, ok(i + 1, j + 1, n, grid, dp));
  else
    ans = max(ans, ok(i + 1, j - 1, n, grid, dp));
  return dp[i][j] = ans + grid[i][j];
}
void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> grid(2*n + 5, vector<int>(n + 5, 0)), dp(2*n + 5, vector<int>(n + 5, -1));
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++)
      cin >> grid[i][j];
  for (int i = n, t = n - 2; i < 2 * n - 1; i++, t--)
    for (int j = 0; j <= t; j++)
      cin >> grid[i][j];
  cout << ok(0, 0, n, grid, dp) << '\n';
}
//-----------------------------(main)----------------------------------------------------
signed main()
{
  // cout << fixed << showpoint << setprecision(10);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test = 1, T;
  cin >> test;
  for (T = 1; T <= test; T++)
  {
    cout << "Case " << T << ": ";
    solve();
  }
  return 0;
}
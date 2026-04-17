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
const int N = 35;

vector<bool> cr(N,false), cl(N,false);
int n, k;
//------------------------------------------(solve)------------------------------------------
int ok(int i, int j, vector<vector<bool>> grid)
{
  cr.assign(N, false), cl.assign(N, false);
  int cnt = 0;
  for (int ii = 0; ii < n; ii++)
    for (int jj = 0; jj < n; jj++)
      if (grid[ii][jj])
      {
        if (cr[ii] || cl[jj])
          return 0;
        cr[ii] = cl[jj] = true, cnt++;
        if (cnt == k)
          return 1;
      }
  if (i == n || j == n)
    return 0;
  int ans = ok(i + 1, j, grid) + ok(i, j + 1, grid);
  grid[i][j] = true;
  ans += ok(i + 1, j, grid) + ok(i, j + 1, grid);
  return ans;
}
void solve()
{
  cin >> n >> k;
  if (k > n || k == 0)
  {
    cout << 0 << '\n';
    return;
  }
  vector<vector<bool>> grid(n + 5, vector<bool>(n + 5, false));
  cout << ok(0, 0, grid) << '\n';
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
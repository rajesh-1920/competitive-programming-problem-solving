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
const int MOD = 1e7 + 7;

//------------------------------------------(solve)------------------------------------------
int a, b, c, d, e, f;
int fn(int n, vector<int> &dp)
{
  if (n == 0)
    return a;
  if (n == 1)
    return b;
  if (n == 2)
    return c;
  if (n == 3)
    return d;
  if (n == 4)
    return e;
  if (n == 5)
    return f;
  if (dp[n] != -1)
    return dp[n];
  return dp[n] = (fn(n - 1, dp) % MOD + fn(n - 2, dp) % MOD + fn(n - 3, dp) % MOD + fn(n - 4, dp) % MOD + fn(n - 5, dp) % MOD + fn(n - 6, dp) % MOD) % MOD;
}
void solve()
{
  int n;
  cin >> a >> b >> c >> d >> e >> f >> n;
  vector<int> dp(n + 5, -1);
  cout << fn(n, dp) % MOD << '\n';
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
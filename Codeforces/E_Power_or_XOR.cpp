// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  01.06.2026

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
const int N = 2e6 + 10;

int modpow(int a, int b, int m)
{
  int ans = 1;
  while (b)
  {
    if (b & 1)
      ans = (ans * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return ans;
}
// 1048576
//-----------------------------------------------------------------------------------------
void solve(void)
{
  int n, k;
  cin >> n >> k;
  vector<int> v(n), cnt(N, 0);
  for (auto &it : v)
    cin >> it;
  for (int i = 0; i <= k; i++)
    cnt[v[i]]++;
  for (int i = 0; i <= 10; i++)
  {
    cnt[i] %= 2;
    cout << cnt[i];
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
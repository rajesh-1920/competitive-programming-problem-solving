// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  06.06.2026

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
  vector<int> v(n);
  int car = 0, ans = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    if (i == 0)
      ans = v[i];
    else
    {
      v[i] += car;
      if (v[i] < ans)
      {
        int lagbe = (ans - v[i] + 1) / (i + 1);
        v[i] += (lagbe * i);
        ans -= lagbe;
        if (ans > v[i])
          ans--, v[i] += i;
      }
      if (v[i] >= ans)
        car = v[i] - ans;
    }
    ans = max(ans, 0LL);
    cout << ans << ' ';
  }
  cout << '\n';
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
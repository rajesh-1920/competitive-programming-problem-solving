// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  31.05.2026

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
const int N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
  int n, q;
  cin >> n >> q;
  vector<int> v(n), cnt1(n, 0), cnt0(n, 0);
  set<int> st;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    cnt1[i] = v[i], cnt0[i] = v[i] ^ 1;
    if (i)
    {
      cnt1[i] += cnt1[i - 1], cnt0[i] += cnt0[i - 1];
      if (v[i] == v[i - 1])
        st.insert(i - 1);
    }
  }
  while (q--)
  {
    int x, y;
    cin >> x >> y;
    x--, y--;
    int c0 = cnt0[y], c1 = cnt1[y];
    if (x > 0)
      c0 -= cnt0[x - 1], c1 -= cnt1[x - 1];
    if (c0 % 3 || c1 % 3)
      cout << -1 << '\n';
    else
    {
      int ans = c0 / 3 + c1 / 3 + 1;
      auto it = st.lower_bound(x);
      if (it != st.end() && (*it) + 1 <= y)
        ans--;
      cout << ans << '\n';
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
  cin >> test;
  for (T = 1; T <= test; T++)
  {
    // cout << "Case " << T << ": ";
    solve();
  }
  return 0;
}
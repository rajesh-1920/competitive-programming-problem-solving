// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  06.06.2026

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
const int N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
  int n, ans = 2, fl = 1, x = 0;
  cin >> n;
  vector<int> v(n), col(n, 0);
  set<int> st;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    if (i && v[i] == v[i - 1])
      x = i;
    st.insert(v[i]);
    col[i] = fl;
    fl = fl == 1 ? 2 : 1;
  }
  if (st.size() == 1)
  {
    ans = 1;
    for (int i = 0; i < n; i++)
      col[i] = 1;
  }
  else if (x)
  {
    ans = 2;
    if (v.front() != v.back() && col.front() == col.back())
    {
      col[x] = (col[x] == 1 ? 2 : 1);
      for (int i = x + 1; i < n; i++)
        col[i] = (col[i - 1] == 1 ? 2 : 1);
    }
  }
  else if (v.front() != v.back() && col.front() == col.back())
  {
    ans = 3;
    col.back() = 3;
  }
  cout << ans << '\n';
  for (auto &it : col)
    cout << it << ' ';
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
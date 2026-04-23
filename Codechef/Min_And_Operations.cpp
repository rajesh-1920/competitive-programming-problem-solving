// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  04.03.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
#define int long long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
void solve(void)
{
  int n, ans = 0;
  cin >> n;
  set<int> st;
  for (int i = 0; i <= n; i++)
    st.insert(i);
  while (st.size() > 1)
  {
    int t1 = *(--st.end());
    ans += t1;
    st.erase(--st.end());
    int t2 = *(--st.end());
    st.erase(--st.end());
    st.insert(t1 & t2);
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
// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  01.04.2026

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
  int n, q;
  cin >> n >> q;
  set<int> st;
  for (int i = 0, x; i < n; i++)
  {
    cin >> x;
    st.insert(x);
  }
  vector<int> v;
  int last = *st.begin();
  st.erase(st.begin());
  for (auto &it : st)
    v.push_back(it - last), last = it;
  sort(all(v));
  vector<int> sum(v.size(), 0);
  if (v.size())
    sum[0] = v[0];
  for (int i = 1; i < v.size(); i++)
    sum[i] = v[i] + sum[i - 1];
  while (q--)
  {
    int x;
    cin >> x;
    int ans = x;
    int i = lower_bound(all(v), x) - v.begin();
    ans += (x * (v.size() - i));
    if (i - 1 >= 0)
      ans += sum[i - 1];
    cout << ans << '\n';
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
    // cout << "Case #" << T << ": ";
    solve();
  }
  return 0;
}
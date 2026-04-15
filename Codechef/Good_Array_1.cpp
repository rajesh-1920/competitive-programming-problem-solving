// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  14.04.2026

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
  int n, ans = 0, temp = 520;
  cin >> n;
  vector<int> v(n);

  for (auto &it : v)
    cin >> it;
  for (int i = 2; i <= n; i++)
  {
    map<int, int> mp;
    multiset<int> st;
    for (int j = 0; j < i; j++)
      mp[v[j]]++;
    for (auto &it : mp)
      st.insert(it.sc);

    if ((*st.begin()) > 1)
    {
      st.erase(st.find(mp[v[i - 1]]));
      mp[v[i - 1]]--;
      if (mp[v[i - 1]])
        st.insert(mp[v[i - 1]]);
      v[i - 1] = temp;
      temp++;
      mp[v[i - 1]]++;
      st.insert(mp[v[i - 1]]);
      ans++;
    }
    for (int j = i; j < n; j++)
    {
      st.erase(st.find(mp[v[i - j]]));
      mp[v[i - j]]--;
      if (mp[v[i - j]])
        st.insert(mp[v[i - j]]);

      if (st.find(mp[v[j]]) != st.end())
        st.erase(st.find(mp[v[j]]));
      mp[v[j]]++;
      st.insert(mp[v[j]]);
      if ((*st.begin()) > 1)
      {
        st.erase(st.find(cnt[v[j]]));
        cnt[v[j]]--;
        if (cnt[v[j]])
          st.insert(cnt[v[j]]);
        v[j] = temp;
        temp++;
        cnt[v[j]]++;
        st.insert(cnt[v[j]]);
        ans++;
      }
    }
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
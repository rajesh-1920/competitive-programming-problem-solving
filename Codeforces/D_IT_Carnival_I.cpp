// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  16.02.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
// #define int long long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

void solve()
{
  int n;
  string s;
  cin >> n >> s;
  priority_queue<pair<int, int>> st;
  bool is = true;
  for (int i = 0; i < n / 2; i++)
    if (s[i] != s[n - i - 1])
    {
      st.push({max(s[i] - s[n - i - 1], s[n - i - 1] - s[i]), i});
      is = false;
    }
  if (is)
  {
    cout << "MH and RJ are friends\n";
    return;
  }
  int fl = 1;
  while (!st.empty())
  {
    int i = st.top().second;
    st.pop();
    if (fl)
      s[i] = s[n - i - 1] = min(s[i], s[n - i - 1]);
    else
      s[i] = s[n - i - 1] = max(s[i], s[n - i - 1]);
    fl ^= 1;
  }
  int ans = 0;
  for (int i = 1; i <= (n + 1) / 2; i++)
    ans += s[i - 1] - 'a';
  cout << ans << '\n';
}

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
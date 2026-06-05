// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  05.06.2026

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
  int k;
  string s, val;
  cin >> s >> val >> k;
  vector<int> v(s.size(), 0);
  for (int i = 0; i < s.size(); i++)
  {
    if (val[s[i] - 'a'] == '0')
      v[i] = 1;
    if (i)
      v[i] += v[i - 1];
  }
  set<int> st;
  for (int i = 0; i < s.size(); i++)
  {
    int x = 0;
    for (int j = i; j < s.size(); j++)
    {
      x |= (1LL << (s[j] - 'a'));
      int bad = v[j];
      if (i)
        bad -= v[i - 1];
      if (bad > k)
        break;
      Dbg(x);
      st.insert(x);
    }
  }
  cout << st.size() << '\n';
  for (auto &it : st)
    cout << it << ' ';
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
// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  16.02.2025

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

//---------------------------------------------------------------------------------
void solve()
{
  int n, m, cnt = 0;
  cin >> n >> m;
  vector<vector<int>> v(n + 5, (vector<int>(m + 5, 0))), row(n + 5, (vector<int>(m + 5, 0)));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> v[i][j], cnt += v[i][j];
  for (int i = 0; i < n; i++)
    for (int j = m - 1; j >= 0; j--)
      row[i][j] = row[i][j + 1] + v[i][j];
  int lw = cnt / 2, i = 0, j = 0;
  cout << (cnt - lw) * lw << '\n';
  string s = "";
  while (true)
  {
    if (i == n && j == m)
      break;
    else if (i == n)
      s += "R", j++;
    else if (j == m)
      s += "D", i++;
    else
    {
      if (lw >= row[i][j])
        s += "D", lw -= row[i][j], i++;
      else
        s += "R", j++;
    }
  }
  cout << s << '\n';
}

//---------------------------------------------------------------------------------

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
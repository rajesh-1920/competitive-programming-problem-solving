// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  16.04.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
// #define int long long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;

//------------------------------------------(N queens)------------------------------------------
void solve()
{
  int k, n, m;
  cin >> k >> n >> m;
  vector<int> v(n), vv(m), ans;
  for (auto &it : v)
    cin >> it;
  for (auto &it : vv)
    cin >> it;
  int i = 0, j = 0;
  while (true)
  {
    if (i < n && j < m)
    {
      if (v[i] == 0)
        k++, ans.push_back(0), i++;
      else if (vv[j] == 0)
        k++, ans.push_back(0), j++;
      else if (k >= v[i])
        ans.push_back(v[i]), i++;
      else if (k >= vv[j])
        ans.push_back(vv[j]), j++;
      else
      {
        cout << -1 << '\n';
        return;
      }
    }
    else if (i < n)
    {
      if (v[i] == 0)
        k++, ans.push_back(0), i++;
      else if (k >= v[i])
        ans.push_back(v[i]), i++;
      else
      {
        cout << -1 << '\n';
        return;
      }
    }
    else if (j < m)
    {
      if (vv[j] == 0)
        k++, ans.push_back(0), j++;
      else if (k >= vv[j])
        ans.push_back(vv[j]), j++;
      else
      {
        cout << -1 << '\n';
        return;
      }
    }
    else
      break;
  }
  for (auto &it : ans)
    cout << it << ' ';
  cout << '\n';
}

//-----------------------------(Suduko)----------------------------------------------------

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
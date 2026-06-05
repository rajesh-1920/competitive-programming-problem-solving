// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  04.06.2026

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
pair<int, int> ok(const vector<int> &v)
{
  vector<int> t = {-2};
  for (auto &it : v)
    t.push_back(-1), t.push_back(it);
  t.push_back(-1), t.push_back(-3);
  int n = t.size(), center = 0, right = 0;
  vector<int> p(n, 0);
  for (int i = 1; i + 1 < n; i++)
  {
    int mirror = 2 * center - i;
    if (i < right)
      p[i] = min(p[mirror], right - i);
    while (t[i + p[i] + 1] == t[i - p[i] - 1])
      p[i]++;
    if (i + p[i] > right)
      center = i, right = i + p[i];
  }
  int mxlen = 0, centeridx = 0;
  for (int i = 1; i + 1 < n; i++)
    if (p[i] > mxlen)
      mxlen = p[i], centeridx = i;
  int start = (centeridx - mxlen) / 2;
  return {start, mxlen};
}
void solve(void)
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &it : v)
    cin >> it;
  n = 0;
  while (!v.empty())
  {
    auto [a, b] = ok(v);
    vector<int> temp;
    for (int i = 0; i < a; i++)
      temp.push_back(v[i]);
    for (int i = a + b; i < v.size(); i++)
      temp.push_back(v[i]);
    v = move(temp);
    n++;
  }
  cout << n << '\n';
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
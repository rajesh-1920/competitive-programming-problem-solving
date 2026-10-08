// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  08.10.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition
// section)-----------------------------------------
#define Dbg(x) cout << #x << " = " << x << '\n';
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
void solve(void) {
  int n;
  cin >> n;
  vector<vector<int>> v(n, vector<int>(n, -1));
  vector<int> xx = {2, 2, -2, -2, 1, -1, 1, -1};
  vector<int> yy = {1, -1, 1, -1, 2, 2, -2, -2};
  queue<pair<int, int>> q;
  v[0][0] = 0;
  q.push({0, 0});
  while (!q.empty()) {
    auto [a, b] = q.front();
    q.pop();
    for (int i = 0; i < xx.size(); i++) {
      int x = a + xx[i], y = b + yy[i];
      if (x >= 0 && x < n && y >= 0 && y < n && v[x][y] == -1) {
        q.push({x, y});
        v[x][y] = v[a][b] + 1;
      }
    }
  }
  for (auto &it : v) {
    for (auto &ii : it)
      cout << ii << ' ';
    cout << '\n';
  }
}
//-----------------------------------------------------------------------------------------
signed main() {
  // cout << fixed << showpoint << setprecision(10);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test = 1, T;
  // cin >> test;
  for (T = 1; T <= test; T++) {
    // cout << "Case " << T << ": ";
    solve();
  }
  return 0;
}
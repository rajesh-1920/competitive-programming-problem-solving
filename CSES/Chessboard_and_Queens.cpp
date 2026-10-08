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
bool is(vector<string> &v) {
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) {
      if (v[i][j] == 'q') {
        for (int ii = 0; ii < 8; ii++) {
          if (v[ii][j] == 'q' && ii != i)
            return false;
          if (v[i][ii] == 'q' && ii != j)
            return false;
        }
        for (int ii = i + 1, jj = j + 1; ii < 8 && jj < 8; ii++, jj++)
          if (v[ii][jj] == 'q')
            return false;
        for (int ii = i + 1, jj = j - 1; ii < 8 && jj >= 0; ii++, jj--)
          if (v[ii][jj] == 'q')
            return false;
        for (int ii = i - 1, jj = j - 1; ii >= 0 && jj >= 0; ii--, jj--)
          if (v[ii][jj] == 'q')
            return false;
        for (int ii = i - 1, jj = j + 1; ii >= 0 && jj < 8; ii--, jj++)
          if (v[ii][jj] == 'q')
            return false;
      }
    }
  return true;
}
void ok(int i, vector<string> &v, int &ans) {
  if (i == 8) {
    ans++;
    return;
  }
  for (int j = 0; j < 8; j++) {
    if (v[i][j] == '.') {
      v[i][j] = 'q';
      if (is(v))
        ok(i + 1, v, ans);
      v[i][j] = '.';
    }
  }
}
void solve(void) {
  vector<string> v(8);
  for (auto &it : v)
    cin >> it;
  int ans = 0;
  ok(0, v, ans);
  cout << ans << '\n';
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
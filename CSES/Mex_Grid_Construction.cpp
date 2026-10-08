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
  vector<vector<int>> v(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++)
    v[0][i] = i;
  set<int> st;
  for (int j = 0; j <= 1000; j++)
    st.insert(j);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      set<int> temp;
      for (int ii = 0; ii < i; ii++) {
        st.erase(v[ii][j]);
        temp.insert(v[ii][j]);
      }
      for (int ii = 0; ii < j; ii++) {
        st.erase(v[i][ii]);
        temp.insert(v[i][ii]);
      }
      v[i][j] = (*st.begin());
      for (auto &it : temp)
        st.insert(it);
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
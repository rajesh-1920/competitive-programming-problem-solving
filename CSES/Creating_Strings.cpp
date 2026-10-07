// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  07.10.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition
//section)-----------------------------------------
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
  string s;
  cin >> s;
  vector<string> ans;
  sort(all(s));
  do {
    ans.push_back(s);
  } while (next_permutation(all(s)));
  cout << ans.size() << '\n';
  for (auto &it : ans)
    cout << it << '\n';
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
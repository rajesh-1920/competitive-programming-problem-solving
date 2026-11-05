// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  05.11.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition
// section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
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
  vector<int> v(3);
  for (auto &it : v)
    cin >> it;
  sort(all(v));
  if (v[0] * v[0] + v[1] * v[1] == v[2] * v[2])
    cout << "yes\n";
  else
    cout << "no\n";
}
//-----------------------------------------------------------------------------------------
signed main() {
  // cout << fixed << showpoint << setprecision(10);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test = 1, T;
  cin >> test;
  for (T = 1; T <= test; T++) {
    cout << "Case " << T << ": ";
    solve();
  }
  return 0;
}
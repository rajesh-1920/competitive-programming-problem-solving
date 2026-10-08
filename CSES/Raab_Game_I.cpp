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
  int n, a, b;
  cin >> n >> a >> b;
  if ((a == 0 && b) || (a && b == 0) || (a + b > n)) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  vector<int> aa(n), bb(n);
  for (int i = 0; i < n; i++)
    aa[i] = bb[i] = i + 1;

  if (a) {
    n = a + b;
    int t = 1;
    for (int i = n - a; i < n; i++)
      bb[i] = t++;
    for (int i = 0; i < n - a; i++)
      bb[i] = t++;
  }

  for (auto &it : aa)
    cout << it << ' ';
  cout << '\n';
  for (auto &it : bb)
    cout << it << ' ';
  cout << '\n';
}
//-----------------------------------------------------------------------------------------
signed main() {
  // cout << fixed << showpoint << setprecision(10);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test = 1, T;
  cin >> test;
  for (T = 1; T <= test; T++) {
    // cout << "Case " << T << ": ";
    solve();
  }
  return 0;
}
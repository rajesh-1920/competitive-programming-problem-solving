// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  05.10.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition
// section)-----------------------------------------
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
void solve(void) {
  int a, b, k;
  cin >> a >> b >> k;
  vector<int> v(k);
  map<int, int> mp;
  for (auto &it : v)
    cin >> it;
  vector<pair<int, int>> vp(k);
  for (int i = 0; i < k; i++) {
    cin >> vp[i].sc;
    vp[i].fi = v[i];
    mp[vp[i].sc]++;
  }
  sort(all(vp));
  int ans = 0, l = 0, temp = k;
  while (l < k) {
    int r = 0;
    for (int i = l; i < k; i++) {
      if (vp[i].fi != vp[l].fi)
        break;
      mp[vp[i].sc]--;
      r = i;
    }
    int cnt = r - l + 1;
    while (l <= r) {
      ans += (temp - cnt - mp[vp[l].sc]);
      l++;
    }
    temp -= cnt;
  }
  cout << ans << '\n';
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
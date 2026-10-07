// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  06.10.2026

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
  string s, temp = "";
  cin >> s;
  map<char, int> mp;
  for (auto &it : s)
    mp[it]++;
  s = "";
  char ch = '*';
  for (auto &it : mp) {
    if (it.sc & 1) {
      if (ch != '*') {
        cout << "NO SOLUTION\n";
        return;
      }
      ch = it.fi;
    }
    for (int i = 0; i < it.sc / 2; i++)
      s.push_back(it.fi), temp.push_back(it.fi);
  }
  if (ch != '*')
    s.push_back(ch);
  reverse(all(temp));
  cout << s;
  cout << temp << '\n';
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
// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  03.11.2026

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
  int n, m;
  cin >> n >> m;
  priority_queue<pair<int, int>> pq;
  while (n--) {
    int x;
    cin >> x;
    int l = 0, cnt = 0, fl = 1;
    while (x) {
      if (x % 10)
        fl = 0;
      cnt += fl, l++;
      x /= 10;
    }
    pq.push({cnt, l});
  }
  while (pq.size() > 1) {
    auto [cnt, l] = pq.top();
    pq.pop();
    pq.push({0, l - cnt});
    auto [cnt1, l1] = pq.top();
    pq.pop();
    auto [cnt2, l2] = pq.top();
    pq.pop();
    pq.push({cnt2, l1 + l2});
  }
  auto [cnt, l] = pq.top();
  if (l - cnt > m)
    cout << "Sasha\n";
  else
    cout << "Anna\n";
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
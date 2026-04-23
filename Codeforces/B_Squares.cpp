// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  01.02.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
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
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    // vector<vector<int>> v(110, vector<int>(110, 0));
    for (auto &it : v)
        cin >> it;
    if (k > n)
    {
        cout << -1;
        return;
    }
    sort(all(v));
    int t = 0;
    while (k--)
    {
        t = v.back();
        v.pop_back();
    }
    if (t == v.back())
        cout << -1;
    else
        cout << 0 << ' ' << t;
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
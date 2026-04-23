// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  09.02.2025

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
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    cin >> m;
    int cnt = 0;
    v[0] = min(v[0], m - v[0]);
    for (int i = 1; i < n; i++)
    {
        int mn = min(v[i], m - v[i]);
        int mx = max(v[i], m - v[i]);
        if (mn >= v[i - 1])
            v[i] = mn;
        else if (mx < v[i - 1])
        {
            cout << "NO\n";
            return;
        }
        else
            v[i] = mx;
    }
    cout << "YES\n";
}
//-----------------------------------------------------------------------------------------
signed main()
{
    // cout << fixed << showpoint << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1, T;
    cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}
// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  25.03.2025

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
    int n, q;
    cin >> n >> q;
    map<int, int> mp, tm;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        mp[x]++;
        mp[y + 1]--;
    }
    int t = 0;
    for (auto it : mp)
    {
        tm[it.fi] = it.sc + t;
        t += it.sc;
        // cout << it.fi << ' ' << tm[it.fi] << '\n';
    }
    while (q--)
    {
        int x;
        cin >> x;
        auto it = tm.lower_bound(x);
        if (it == tm.end())
        {
            cout << 0 << '\n';
            continue;
        }
        else if ((*it).fi == x)
            cout << (*it).sc << '\n';
        else
        {
            if (it == tm.begin())
                cout << 0 << '\n';
            else
            {
                it--;
                cout << (*it).sc << '\n';
            }
        }
    }
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
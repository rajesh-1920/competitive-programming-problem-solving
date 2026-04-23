// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  31.10.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
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
void solve(void)
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<pair<int, int>> ans;
    if (a == 0)
    {
        if (b == 0)
            for (int i = 1; i <= n; i++)
                ans.push_back({i, i});
        else
        {
            cout << "NO\n";
            return;
        }
    }
    else if (b == 0)
    {
        if (a == 0)
            for (int i = 1; i <= n; i++)
                ans.push_back({i, i});
        else
        {
            cout << "NO\n";
            return;
        }
    }
    else if (a + b > n)
    {
        cout << "NO\n";
        return;
    }
    else
    {
        for (int i = 1; i <= n; i++)
            ans.push_back({i, i});
        int t = 0;
        for (int i = a + 1;; i++, t++)
        {
            if (t == b)
                break;
            ans[t].sc = i;
        }
        for (int i = 1; i <= a; i++, t++)
            ans[t].sc = i;
    }
    cout << "YES\n";
    for (auto it : ans)
        cout << it.fi << ' ';
    cout << '\n';
    for (auto it : ans)
        cout << it.sc << ' ';
    cout << '\n';
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
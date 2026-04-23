// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  26.05.2025

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
const int inf = 1e18 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    multiset<int> sx, sy;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
        sx.insert(x);
        sy.insert(y);
    }

    if (n == 1)
    {
        cout << 1 << '\n';
        return;
    }

    int x1 = *sx.begin(), x2 = *(--sx.end());
    int y1 = *sy.begin(), y2 = *(--sy.end());
    int t1 = x2 - x1 + 1, t2 = y2 - y1 + 1;
    int ans = t1 * t2;

    for (auto it : v)
    {
        sx.erase(sx.find(it.fi));
        sy.erase(sy.find(it.sc));

        x1 = *sx.begin(), x2 = *(--sx.end());
        y1 = *sy.begin(), y2 = *(--sy.end());
        t1 = x2 - x1 + 1;
        t2 = y2 - y1 + 1;

        int temp = t1 * t2;
        if (temp >= n)
            ans = min(ans, temp);
        else
            ans = min(ans, temp + (min(t1, t2)));

        sx.insert(it.fi);
        sy.insert(it.sc);
    }

    cout << ans << '\n';
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
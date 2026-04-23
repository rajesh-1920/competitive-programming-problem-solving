// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  13.11.2025

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
    int n, m;
    cin >> n >> m;
    vector<int> pos(n + 1, n + 5), val(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
        pos[val[i]] = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (pos[i] < pos[i - 1])
            ans++;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        if (val[x] < val[y])
            swap(x, y);
        int v1 = val[x], v2 = val[y];
        if (pos[v1] < pos[v2])
            ans--;
        else if (pos[v1] > pos[v2])
            ans++;
        if (v1 > 1 && pos[v1 - 1] > x && pos[v1 - 1] < y)
            ans--;
        if (v1 > 1 && pos[v1 - 1] < x && pos[v1 - 1] > y)
            ans++;
        if (v1 < n && pos[v1 + 1] < x && pos[v1 + 1] > y)
            ans--;
        if (v1 < n && pos[v1 + 1] > x && pos[v1 + 1] < y)
            ans++;
        if (v2 > 1 && pos[v2 - 1] > y && pos[v2 - 1] < x)
            ans--;
        if (v2 > 1 && pos[v2 - 1] < y && pos[v2 - 1] > x)
            ans++;
        if (v2 < n && pos[v2 + 1] < y && pos[v2 + 1] > x)
            ans--;
        if (v2 < n && pos[v2 + 1] > y && pos[v2 + 1] < x)
            ans++;
        swap(pos[v1], pos[v2]);
        swap(val[x], val[y]);
        cout << ans << '\n';
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
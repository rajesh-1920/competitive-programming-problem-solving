// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  08.04.2025

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
const int N = 1e3;
//-----------------------------------------------------------------------------------------
vector<int> g[N];
int fl = 0, sz;
int ok(int n, int pre)
{
    //dbg(n);
    // dbg(pre);
    if (n > sz || fl)
        return 0;
    if (g[n].size() == 0)
    {
        fl = 1;
        return 0;
    }
    int ans = inf;
    for (auto it : g[n])
    {
        int an = ok(n + 1, it);
        ans = min(ans, an + max(it - pre, pre - it));
    }
    return ans;
}
void solve(void)
{
    for (int i = 0; i < N; i++)
        g[i].clear();
    int n, m;
    cin >> n >> m;
    sz = n;
    vector<string> v(n);
    for (auto &it : v)
        cin >> it;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            string s;
            cin >> s;
            if (s == v[j])
                g[j + 1].push_back(i);
        }
    }
    int ans = inf;
    fl = 0;
    for (auto it : g[1])
    {
        ans = min(ans, ok(2, it) + it);
        // dbg(it);
    }
    if (fl)
        ans = -1;
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
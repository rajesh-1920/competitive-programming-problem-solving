// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  01.04.2025

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
    int n;
    cin >> n;
    vector<int> v(n + 5), pos(n + 5);
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        pos[v[i]] = i;
    }
    for (int i = n; i >= 1; i--)
    {
        if (v[i] == i)
            continue;
        ans.push_back({i, pos[1]});
        swap(v[i], v[pos[1]]);
        swap(pos[v[i]], pos[v[pos[1]]]);
        ans.push_back({pos[i], pos[1]});
        swap(v[pos[i]], v[pos[1]]);
        swap(pos[v[pos[i]]], pos[v[pos[1]]]);
    }
    cout << ans.size() << '\n';
    for (auto it : ans)
        cout << it.fi << ' ' << it.sc << '\n';
    // for (int i = 1; i <= n; i++)
    //     cout << v[i] << ' ';
    // cout << '\n';
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
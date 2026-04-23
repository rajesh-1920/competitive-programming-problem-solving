// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  10.08.2025

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
//------------------------------(solve)----------------------------------------------------
void solve(void)
{
    int n;
    cin >> n;
    vector<int> pos(2 * n + 10, -1), v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        pos[v[i]] = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int x = v[i]; x < 2 * n + 10; x += v[i])
        {
            int t = x / v[i];
            if (pos[t] != -1)
            {
                int j = pos[t];
                if (i < j && v[i] * v[j] == i + j)
                    ans++;
            }
        }
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
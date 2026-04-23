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
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].fi, v[i].sc = i+1r;
    sort(all(v));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            int l = 0, r = n - 1, t = x - v[i].fi - v[j].fi;
            if (t <= 0)
                break;
            while (l <= r)
            {
                int m = (l + r) / 2;
                if (v[m].fi > t)
                    r = m - 1;
                else
                    l = m + 1;
            }
            for (int ii = max(0LL, l - 5); ii < n; ii++)
            {
                if (v[ii].fi > t)
                    break;
                if (v[ii].fi == t && ii != i && ii != j)
                {
                    cout << v[ii].sc << ' ' << v[i].sc << ' ' << v[j].sc << '\n';
                    return;
                }
            }
        }
    cout << "IMPOSSIBLE\n";
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
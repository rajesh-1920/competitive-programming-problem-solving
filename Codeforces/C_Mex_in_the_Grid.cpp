// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  22.07.2025

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
    int cnt = n * n - 1;
    int lr = 0, rr = n - 1, lc = 0, rc = n - 1;
    vector<vector<int>> v(n, vector<int>(n));
    while (lr <= rr && lc <= rc)
    {
        for (int i = rc; i >= lc; i--)
            v[lr][i] = cnt--;
        for (int i = lr + 1; i <= rr; i++)
            v[i][lc] = cnt--;
        if (rr == lr)
            break;
        for (int i = lc + 1; i <= rc; i++)
            v[rr][i] = cnt--;
        for (int i = rr - 1; i > lr; i--)
            v[i][rc] = cnt--;
        lr++, rr--, lc++, rc--;
    }

    for (auto it : v)
    {
        for (auto ii : it)
            cout << ii << ' ';
        cout << '\n';
    }
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
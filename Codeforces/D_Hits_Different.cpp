// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  11.07.2025

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
const int N = 1e3 + 500;
const int NN = 1e6 + 500;
//------------------------------(solve)----------------------------------------------------
vector<int> ans[N];
vector<pair<int, int>> mp;
void ok()
{
    int t = 1;
    for (int i = 0; i < N; i++)
    {
        int s = 0;
        for (int j = 0; j <= i; j++)
        {
            s += t * t;
            ans[i].push_back(s);
            mp.push_back({i, j});
            t++;
        }
    }
}
void solve(void)
{
    int n;
    cin >> n;
    int an = 0, r = mp[n - 1].fi, ll = mp[n - 1].sc, rr = mp[n - 1].sc;
    while (r >= 0)
    {
        if (ll == 0 && rr == r)
            an += ans[r][r], rr--, r--;
        else
        {
            if (ll)
                an += ans[r][rr] - ans[r][ll - 1], ll--;
            else
                an += ans[r][rr];
            r--;
            rr = min(r, rr);
        }
    }
    cout << an << '\n';
}
//-----------------------------------------------------------------------------------------
signed main()
{
    // cout << fixed << showpoint << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1, T;
    cin >> test;
    ok();
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}
// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  01.01.2026

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
    int n;
    string s;
    cin >> n >> s;
    int mxa = 0, mxb = 0, ca = 0, cb = 0, cca = 0, ccb = 0;
    for (auto it : s)
    {
        if (it == 'a')
            ca++, cca++, ccb = 0;
        else
            cb++, ccb++, cca = 0;
        mxa = max(mxa, cca), mxb = max(mxb, ccb);
    }
    int ans = -1;
    if (ca == cb)
        ans = 0;
    else if (ca > cb and mxa >= (ca - cb) and cb)
        ans = ca - cb;
    else if (ca < cb and mxb >= (cb - ca) and ca)
        ans = cb - ca;
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
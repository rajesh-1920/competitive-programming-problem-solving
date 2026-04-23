// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  25.02.2025

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
    string s;
    cin >> n >> s;
    int cntup = 0, cntdo = 0;
    for (auto it : s)
        if (it == '-')
            cntup++;
        else
            cntdo++;
    if (n < 3 || cntdo == 0 || cntup < 2)
    {
        cout << 0 << '\n';
        return;
    }
    int t = cntup / 2;
    cntup -= t;
    int ans = t * cntdo * cntup;
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
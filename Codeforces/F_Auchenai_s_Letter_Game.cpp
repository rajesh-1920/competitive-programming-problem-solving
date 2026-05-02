// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  02.05.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
#define fi first
#define sc second
#define int long int

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int MOD = 1e9 + 7;
const int N = 1e7 + 1;

//-----------------------------------------------------------------------------------------
void solve(void)
{
    int a, b, c, x, y, z, ans = 0;
    cin >> a >> b >> c >> x >> y >> z;
    string s;
    if (x + y > z)
        while (a && b && c)
            ans += x + y, a--, b--, c--, s += "IGM";
    else
        while (a && c)
            ans += z, a--, c--, s += "IM";
    if (y > z)
        while (b && c)
            ans += y, b--, c--, s += "GM";
    else
        while (a && c)
            ans += z, a--, c--, s += "IM";
    while (b && c)
        ans += y, b--, c--, s += "GM";
    while (a && b && c)
        ans += x + y, a--, b--, c--, s += "IGM";
    while (a && c)
        ans += z, a--, c--, s += "IM";
    while (a)
        a--, s += "I";
    while (b)
        b--, s += "G";
    while (c)
        c--, s += "M";
    cout << ans << '\n';
    cout << s << '\n';
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
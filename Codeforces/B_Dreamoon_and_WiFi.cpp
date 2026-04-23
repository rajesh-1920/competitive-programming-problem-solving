// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  15.01.2025

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const ll inf = 9e15 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    string s1, s2;
    cin >> s1 >> s2;
    ll tar = 0, now = 0, cnt = 0;

    for (ll i = 0; i < s1.size(); i++)
    {
        if (s1[i] == '+')
            tar++;
        else
            tar--;
        if (s2[i] == '+')
            now++;
        else if (s2[i] == '-')
            now--;
        else
            cnt++;
    }
    ll x = 0, cc = 0;
    for (ll i = 0; i < (1 << cnt); i++)
    {
        ll t = now;
        for (ll j = 0; j < cnt; j++)
        {
            if (i & (1 << j))
                t++;
            else
                t--;
        }
        if (t == tar)
            x++;
        cc++;
    }    
    double x1 = x, x2 = cc;
    double ans = (x1 / x2);
    cout << ans << '\n';
}
//-----------------------------------------------------------------------------------------
int main()
{
    cout << fixed << showpoint << setprecision(12);
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
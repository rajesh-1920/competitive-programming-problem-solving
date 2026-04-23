// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  27.01.2025

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
const ll inf = 9e16 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    ll n, need;
    cin >> n >> need;
    ll ans = inf;
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= n; j++)
        {
            for (ll k = 0; k <= n; k++)
            {
                for (ll l = 0; l <= n; l++)
                {
                    ll t = 2 * i + 3 * j + 4 * k + 5 * l;
                    if (i + j + k + l == n && t == need)
                        ans = min(ans, i);
                }
            }
        }
    }
    cout << ans << '\n';
}
//-----------------------------------------------------------------------------------------
int main()
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
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
const ll inf = 9e15 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    ll n;
    cin >> n;
    // vector<vector<ll>> v(110, vector<ll>(110, 0)), sum(110, vector<ll>(110, 0));
    //  vector<ll> row(110, 0), col(110, 0);
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        ll t1, t2;
        if (x1 >= y1)
            t1 = x1 - y1 + 1;
        else
            t1 = y1 - x1 + 1;
        if (x2 >= y2)
            t2 = x2 - y2 + 1;
        else
            t2 = y2 - x2 + 1;
        ans += t1 * t2;
    }
    /*for (ll i = 1; i <= 100; i++)
    {
        for (ll j = 1; j <= 100; j++)
        {
            sum[i][j] = v[i][j] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= 100; i++)
    {
        for (ll j = 1; j <= 100; j++)
        {
            // cout << sum[i][j] << ' ';
            //  cout << v[i][j] << ' ';
            ans += sum[i][j];
        }
        // cout << '\n';
    }*/
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
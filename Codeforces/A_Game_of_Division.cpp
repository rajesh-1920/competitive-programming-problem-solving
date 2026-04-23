// Author:  Rajesh Biswas
// CF    :  rajesh19
// Date  :  10.12.2024

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
const ll N = 1e9 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &it : v)
        cin >> it;
    for (ll i = 0; i < n; i++)
    {
        ll fl = 1;
        for (ll j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            ll t = abs(v[i] - v[j]);
            if (t % k == 0)
            {
                fl = 0;
                break;
            }
        }
        if (fl)
        {
            cout << "YES\n"
                 << i + 1 << '\n';
            return;
        }
    }
    cout << "NO\n";
}
//-----------------------------------------------------------------------------------------
int main()
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
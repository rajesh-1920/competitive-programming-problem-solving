// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  21.01.2025

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
    ll n, m;
    cin >> m >> n;
    map<string, ll> mp;
    while (m--)
    {
        string s;
        ll t;
        cin >> s >> t;
        mp[s] = t;
    }
    while (n--)
    {
        ll ans = 0;
        string s;
        while (cin >> s)
        {
            if (s[0] == '.')
                break;
            if (mp.find(s) != mp.end())
                ans += mp[s];
        }
        cout << ans << '\n';
    }
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
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
    ll n, x;
    cin >> n >> x;
    map<ll, vector<ll>> mp;
    vector<pair<ll, ll>> v;
    for (ll i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        v.push_back({x, i});
        mp[x].push_back(i);
    }
    for (auto it : v)
    {
        ll now = it.fi;
        ll need = x - now;
        if (mp.find(need) == mp.end())
            continue;
        // dbg(need);
        for (auto ii : mp[need])
        {
            if (it.sc != ii)
            {
                cout << ii << ' ' << it.sc << '\n';
                return;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
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
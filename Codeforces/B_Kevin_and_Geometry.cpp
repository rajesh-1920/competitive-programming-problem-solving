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
const ll N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &it : v)
    {
        cin >> it;
    }
    sort(all(v));
    map<ll, vector<ll>> mp;
    for (ll i = 0; i + 1 < n; i++)
    {
        ll dif = v[i + 1] - v[i];
        mp[dif].push_back(i);
        // cout << v[i] << ' ';
    }
    for (ll i = 0; i + 1 < n; i++)
    {
        if (v[i] == v[i + 1])
        {
            ll t = v[i] + v[i + 1];
            for (auto it : mp)
            {
                // cout << it->fi << ' ';
                if (it.fi >= t)
                    break;
                for (auto ii : it.sc)
                {
                    // dbg(ii);
                    if (ii == i || ii == i + 1 || ii + 1 == i)
                        continue;
                    cout << v[i] << ' ' << v[i + 1] << ' ' << v[ii] << ' ' << v[ii + 1] << '\n';
                    return;
                }
            }
        }
    }
    cout << -1 << '\n';
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
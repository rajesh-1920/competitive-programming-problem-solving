// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  26.01.2025

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
map<vector<ll>, ll> mp;
ll ok(vector<ll> &v)
{
    if (mp.find(v) != mp.end())
        return mp[v];
    if (v.size() == 1)
        return v[0];
    ll ans = 0;
    vector<ll> temp, t2;
    for (ll i = v.size() - 1; i >= 0; i--)
    {
        if (i > 0)
            temp.push_back(v[i - 1] - v[i]);
        if (i > 0)
            t2.push_back(v[i] - v[i - 1]);
        ans += v[i];
    }
    ans = max(ans, ok(t2));
    return mp[v] = max(ok(temp), ans);
}
void solve(void)
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &it : v)
        cin >> it;
    cout << ok(v) << '\n';
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
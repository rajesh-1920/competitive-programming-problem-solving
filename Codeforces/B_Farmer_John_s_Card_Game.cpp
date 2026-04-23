// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  19.01.2025

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
    ll n, m;
    cin >> n >> m;
    vector<ll> v[n + 1];
    map<ll, ll> mp;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            ll x;
            cin >> x;
            v[i].push_back(x);
            mp[x] = i;
        }
    }
    vector<ll> ans;
    set<ll> st;
    for (ll i = 0; i < n; i++)
    {
        ans.push_back(mp[i]);
        st.insert(mp[i]);
    }
    if (st.size() != n)
    {
        cout << -1 << '\n';
        return;
    }
    ll t = 0;
    for (ll i = n; i < n * m; i++)
    {
        if (mp[i] != ans[t])
        {
            cout << -1 << '\n';
            // dbg(t);
            return;
        }
        t++;
        if (t == n)
            t = 0;
    }
    for (auto it : ans)
        cout << it << ' ';
    cout << '\n';
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
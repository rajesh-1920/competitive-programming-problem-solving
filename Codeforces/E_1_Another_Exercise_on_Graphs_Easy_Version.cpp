// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  11.01.2025

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
const ll N = 400 + 10;
//-----------------------------------------------------------------------------------------
vector<pair<ll, ll>> g[N];
map<pair<ll, ll>, ll> mp;
void ok(ll &a, ll &b, ll &k)
{
    priority_queue<ll> ans;
    multiset<pair<ll, ll>> st;
    vector<ll> par(N, -1), dis(N, inf);
    st.insert({0, a});
    dis[a] = 0;
    while (!st.empty())
    {
        ll node = (*st.begin()).sc;
        ll wg = (*st.begin()).fi;
        st.erase(st.begin());
        for (auto it : g[node])
        {
            if (dis[it.sc] > dis[node] + it.fi)
            {
                dis[it.sc] = dis[node] + it.fi;
                st.insert({it.fi, it.sc});
                par[it.sc] = node;
            }
        }
    }
    while (true)
    {
        cout<<b<<' ';
        ll x = par[b];
        if (x == -1)
            break;
        ll y = b;
        if (x > y)
            swap(x, y);
        ans.push(mp[{x, y}]);
        b = par[b];
    }

    while (!ans.empty())
    {
        k--;
        if (k == 0)
        {
            cout << ans.top() << '\n';
            break;
        }
        ans.pop();
    }
}
void solve(void)
{
    ll n, m, q;
    cin >> n >> m >> q;
    while (m--)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        if (x > y)
            swap(x, y);
        mp[{x, y}] = w;
        g[x].push_back({w, y});
        g[y].push_back({w, x});
    }
    while (q--)
    {
        ll x, y, k;
        cin >> x >> y >> k;
        ok(x, y, k);
    }
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
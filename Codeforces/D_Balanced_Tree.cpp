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
const ll N = 2e5 + 10;
//-----------------------------------------------------------------------------------------
vector<ll> g[N], pls(N, 0), mn(N), mx(N);

void dfs(ll node, ll par = -1)
{
    for (auto it : g[node])
    {
        if (it == par)
            continue;
        // dbg(it);

        mn[it] += pls[node];
        pls[it] = pls[node];
        if (mn[node] > mn[it])
        {
            ll lagbe = mn[node] - mn[it];
            mn[it] -= pls[node];
            ll hate = mx[it] - mn[it];
            mn[it] += pls[node];
            if (lagbe > hate)
            {
                pls[it] += lagbe - hate;
                mn[it] = mn[node];
            }
            else
                mn[it] = mn[node];
        }
        // dbg(mn[node]);

        dfs(it, node);
    }
}
void solve(void)
{
    ll n;
    cin >> n;
    ll ans = 0, mxx = 0, t = 1;
    for (ll i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        mx[i] = y;
        mn[i] = x;
        if (mxx < x)
        {
            mxx = x;
            t = i;
        }
        pls[i] = 0;
    }
    for (ll i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(t);
    // dbg(t);
    ll mmn = 0;
    ll ttt = t;
    for (ll i = 1; i <= n; i++)
    {
        if (mmn < mn[i])
        {
            mmn = mn[i];
            t = i;
        }
        pls[i] = 0;
    }
    dfs(t);
    ll an = 0;
    set<ll> st;
    for (ll i = 1; i <= n; i++)
    {
        g[i].push_back(1);
        g[i].clear();
        // an = max(an, mn[i]);
        pls[i] = 0;
        // cout << i << ' ' << mn[i] << '\n';
        st.insert(mn[i]);
    }
    //dbg(mn[ttt]);
    if (st.size() > 1)
        st.erase(--st.end());
    //for (auto it : st)
       // cout << it << ' ';
    cout << *(--st.end()) << '\n';
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
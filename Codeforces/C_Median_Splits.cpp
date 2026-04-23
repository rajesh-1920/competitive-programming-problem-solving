// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  31.05.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
#define ll long long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const ll inf = 9e16 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; // multiple value
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // single
// must use ll
// ll pos = st.order_of_key(5);
// ll val = *st.find_by_order(2);
//-----------------------------------------------------------------------------------------
void solve(void)
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &it : v)
        cin >> it;

    {
        ll left = inf;
        ordered_set<ll> st;
        ll fl = 0;
        for (ll i = 0; i < n; i++)
        {
            st.insert(v[i]);
            ll val = *st.find_by_order((st.size() - 1) / 2);
            if (fl && val > k)
            {
                left = i;
                break;
            }
            if (val <= k)
                fl = 1;
        }
        ordered_set<ll> r, l;
        for (ll i = left; i < n; i++)
            r.insert(v[i]);
        for (ll i = left; i + 1 < n; i++)
        {
            r.erase(r.upper_bound(v[i]));
            l.insert(v[i]);
            ll val1 = *l.find_by_order((l.size() - 1) / 2);
            ll val2 = *r.find_by_order((r.size() - 1) / 2);
            if (val1 <= k || val2 <= k)
            {
                cout << "YES\n";
                return;
            }
        }
    }
    {
        ll left = -inf;
        ordered_set<ll> st;
        ll fl = 0;
        for (ll i = n - 1; i >= 0; i--)
        {
            st.insert(v[i]);
            ll val = *st.find_by_order((st.size() - 1) / 2);
            if (fl && val > k)
            {
                left = i;
                break;
            }
            if (val <= k)
                fl = 1;
        }
        ordered_set<ll> r, l;
        for (ll i = left; i >= 0; i--)
            r.insert(v[i]);
        for (ll i = left; i > 0; i--)
        {
            r.erase(r.upper_bound(v[i]));
            l.insert(v[i]);
            ll val1 = *l.find_by_order((l.size() - 1) / 2);
            ll val2 = *r.find_by_order((r.size() - 1) / 2);
            if (val1 <= k || val2 <= k)
            {
                cout << "YES\n";
                return;
            }
        }
    }
    {
        ll left = -inf;
        ordered_set<ll> st;
        for (ll i = n - 1; i >= 0; i--)
        {
            st.insert(v[i]);
            ll val = *st.find_by_order((st.size() - 1) / 2);
            if (val <= k)
            {
                left = i - 1;
                break;
            }
        }
        ordered_set<ll> r, l;
        for (ll i = left; i >= 0; i--)
            r.insert(v[i]);
        for (ll i = left; i > 0; i--)
        {
            r.erase(r.upper_bound(v[i]));
            l.insert(v[i]);
            ll val1 = *l.find_by_order((l.size() - 1) / 2);
            ll val2 = *r.find_by_order((r.size() - 1) / 2);
            if (val1 <= k || val2 <= k)
            {
                cout << "YES\n";
                return;
            }
        }
    }
    {
        ll left = inf;
        ordered_set<ll> st;
        for (ll i = 0; i < n; i++)
        {
            st.insert(v[i]);
            ll val = *st.find_by_order((st.size() - 1) / 2);
            if (val <= k)
            {
                left = i + 1;
                break;
            }
        }
        ordered_set<ll> r, l;
        for (ll i = left; i < n; i++)
            r.insert(v[i]);
        for (ll i = left; i + 1 < n; i++)
        {
            r.erase(r.upper_bound(v[i]));
            l.insert(v[i]);
            ll val1 = *l.find_by_order((l.size() - 1) / 2);
            ll val2 = *r.find_by_order((r.size() - 1) / 2);
            if (val1 <= k || val2 <= k)
            {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}
//-----------------------------------------------------------------------------------------
signed main()
{
    // cout << fixed << showpoll << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test = 1, T;
    cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}
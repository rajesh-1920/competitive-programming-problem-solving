// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  20.01.2025

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
    vector<ll> v(m);
    multiset<ll> st;
    while (n--)
    {
        ll x;
        cin >> x;
        st.insert(x);
    }
    for (auto &it : v)
        cin >> it;
    sort(all(v));
    ll i = 0;
    while (i < m)
    {
        if (st.size() == 0)
        {
            cout << 'NO\n';
            return;
        }
        auto it = st.begin();
        ll t1 = *it;
        st.erase(st.begin());
        if (t1 == v[i])
        {
            i++;
            continue;
        }
        if (st.size() == 0)
        {
            cout << "NO\n";
            return;
        }
        auto iit = st.begin();
        ll t2 = *iit;
        st.erase(st.begin());
        if (t2 - t1 > 1)
        {
            cout << "NO\n";
            return;
        }
        st.insert(t1 + t2);
    }
    if (st.size())
        cout << "NO\n";
    else
        cout << "YES\n";
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
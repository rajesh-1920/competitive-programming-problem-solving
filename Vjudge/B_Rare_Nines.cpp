// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  07.01.2025

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
const ll N = 2e6 + 10;
//-----------------------------------------------------------------------------------------
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
//-----------------------------------------------------------------------------------------*/
ll is[N], hp[N];
ordered_set st;
void sieve()
{
    for (ll i = 4; i < N; i += 2)
    {
        is[i] = 1;
        hp[i] = 2;
    }
    st.insert(2);
    hp[2] = 2;
    for (ll i = 3; i < N; i += 2)
    {
        if (is[i] == 0)
        {
            st.insert(i);
            hp[i] = i;
            for (ll j = i + i; j < N; j += i)
            {
                is[j] = 1;
                hp[j] = i;
            }
        }
    }
}
void solve(void)
{
    ll n;
    cin >> n;
    ll t = 2, ans = 0;
    ll cnt = 0;
    for (auto it : st)
    {
        cnt++;
        if (n % (it * it) == 0)
        {
            ll x = n / (it * it);
            ll h = hp[x];
            ll t1 = st.order_of_key(h);
            ans += (t1 - cnt) + 1;
        }
    }
    cout << ans << '\n';
}
//-----------------------------------------------------------------------------------------
int main()
{
    // cout << fixed << showpoint << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1, T;
    sieve();
    // cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}
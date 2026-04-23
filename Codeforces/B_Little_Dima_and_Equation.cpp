// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  17.01.2025

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
ll po(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
void solve(void)
{
    ll a, b, c;
    cin >> a >> b >> c;
    set<ll> st;
    for (ll s = 1; s <= 85; s++)
    {
        ll x = b * (po(s, a)) + c;
        ll sum = 0;
        ll t = x;
        while (x)
        {
            sum += (x % 10);
            x /= 10;
        }
        if (sum == s && t > 0 && t < 1000000000)
            st.insert(t);
    }
    cout << st.size() << '\n';
    for (auto it : st)
        cout << it << ' ';
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
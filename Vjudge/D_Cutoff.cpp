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
const ll N = 1e9 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    ll n, x, mn = 500;
    cin >> n >> x;
    multiset<ll> st;
    ll sum = 0;
    for (ll i = 1; i < n; i++)
    {
        ll t;
        cin >> t;
        st.insert(t);
        sum += t;
    }

    for (ll i = 0; i <= 100; i++)
    {
        ll temp = sum;
        st.insert(i);
        ll t = *(st.begin());
        sum -= t;
        t = *(--st.end());
        sum -= t;
        sum += i;
        if (sum >= x)
        {
            cout << i;
            return;
        }
        st.erase(st.find(i));
        sum = temp;
    }
    cout << -1;
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
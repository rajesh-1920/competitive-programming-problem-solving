// Author:  Rajesh Biswas
// Date  :  15.12.2024

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
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
    ll n;
    cin >> n;
    vector<ll> v(n);
    set<ll> st;
    for (ll i = 1; i <= n; i++)
    {
        st.insert(i);
        cin >> v[i - 1];
    }
    for (ll i = 0; i < n; i++)
    {
        if (st.find(v[i]) != st.end())
        {
            cout << v[i] << ' ';
            st.erase(v[i]);
        }
        else
        {
            cout << (*st.begin()) << ' ';
            st.erase(st.begin());
        }
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
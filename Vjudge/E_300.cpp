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
    set<ll> st;
    for (ll a = 9; a >= 0; a--)
    {
        st.insert(a);
        for (ll b = a - 1; b >= 0; b--)
        {
            st.insert(a * 10 + b);
            for (ll c = b - 1; c >= 0; c--)
            {
                st.insert(a * 100 + b * 10 + c);
                for (ll d = c - 1; d >= 0; d--)
                {
                    st.insert(a * 1000 + b * 100 + c * 10 + d);
                    for (ll e = d - 1; e >= 0; e--)
                    {
                        st.insert(a * 10000 + b * 1000 + c * 100 + d * 10 + e);
                        for (ll f = e - 1; f >= 0; f--)
                        {
                            st.insert(a * 100000 + b * 10000 + c * 1000 + d * 100 + e * 10 + f);
                            for (ll g = f - 1; g >= 0; g--)
                            {
                                st.insert(a * 1000000 + b * 100000 + c * 10000 + d * 1000 + e * 100 + f * 10 + g);
                                for (ll h = g - 1; h >= 0; h--)
                                {
                                    st.insert(a * 10000000 + b * 1000000 + c * 100000 + d * 10000 + e * 1000 + f * 100 + g * 10 + h);
                                    for (ll i = h - 1; i >= 0; i--)
                                    {
                                        st.insert(a * 100000000 + b * 10000000 + c * 1000000 + d * 100000 + e * 10000 + f * 1000 + g * 100 + h * 10 + i);
                                        for (ll j = i - 1; j >= 0; j--)
                                        {
                                            st.insert(a * 1000000000 + b * 100000000 + c * 10000000 + d * 1000000 + e * 100000 + f * 10000 + g * 1000 + h * 100 + i * 10 + j);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vector<ll> v;
    for (auto it : st)
    {
        if (it > 0)
        {
            v.push_back(it);
            //cout << it << '\n';
        }
    }
    ll n;
    cin >> n;
    cout << v[n - 1];
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
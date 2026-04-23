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
const ll N = 1e9 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    ll n, q;
    cin >> n >> q;
    vector<ll> v[n];
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 0)
        {
            ll i, x;
            cin >> i >> x;
            v[i].push_back(x);
        }
        else if (t == 1)
        {
            ll i;
            cin >> i;
            for (ll ii = 0; ii + 1 < v[i].size(); ii++)
                cout << v[i][ii] << ' ';
            if (v[i].size())
                cout << v[i][v[i].size() - 1] << '\n';
            else
                cout << '\n';
        }
        else
        {
            ll i;
            cin >> i;
            if (v[i].size())
                v[i].clear();
        }
    }
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
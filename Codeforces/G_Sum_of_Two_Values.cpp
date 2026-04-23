// Author:  Rajesh Biswas
// Date  :  22.10.2024

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
//----------------------------(definition section)-------------------------------------
#define f(i, a, b) for (ll i = a; i < b; i++)
#define scv(v, n) f(i, 0, n) cin >> (v[i]);
#define dbg(x) cout << #x << " = " << x << '\n'
#define nl cout << ("\n")
#define rrr return
#define fi first
#define sc second
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

#define PI acos(-1)
#define MOD 1000000007
#define eps 0.0000000001
#define inf 90000000000000

#define base1 1000002089
#define base2 1000003853
#define hashmod 1000002989
#define N 200009
//------------------------------------------------------------------------------------
void solve(void)
{
    ll n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> v(n);
    f(i, 0, n)
    {
        cin >> v[i].fi;
        v[i].sc = i + 1;
    }
    sort(all(v));
    f(i, 0, n)
    {
        ll l = i + 1, j = n - 1, nd = x - v[i].fi;
        // dbg(nd);
        while (l <= j)
        {
            ll m = (l + j) / 2;
            if (v[m].fi > nd)
                j = m - 1;
            else if (v[m].fi < nd)
                l = m + 1;
            else
            {
                cout << v[i].sc << ' ' << v[m].sc;
                rrr;
            }
        }
    }
    cout << -1;
}
//------------------------------------------------------------------------------------
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
/*
freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
*/
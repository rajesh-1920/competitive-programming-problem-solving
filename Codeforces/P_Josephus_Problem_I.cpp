// Author:  Rajesh Biswas
// Date  :  23.10.2024

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
//----------------------------(definition section)-------------------------------------
#define f(i, a, b) for (ll i = a; i < b; i++)
#define scv(v, n) f(i, 0, n) cin >> (v[i]);
#define dbg(x) cout << #x << " = " << x << '\n';
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
    ll n;
    cin >> n;
    vector<ll> v;
    f(i, 1, n + 1) v.pb(i);
    ll fl = 1;
    while (true)
    {
        if (v.size() == 0)
            break;
        vector<ll> t;
        ll las;
        for (ll i = 0; i < v.size(); i++)
        {
            if (fl)
            {
                if (i & 1)
                {
                    cout << v[i] << ' ';
                    las = i;
                }
                else
                    t.pb(v[i]);
            }
            else
            {
                if (i & 1)
                    t.pb(v[i]);
                else
                {
                    cout << v[i] << ' ';
                    las = i;
                }
            }
        }
        if (v.size() - 1 == las)
            fl = 1;
        else
            fl = 0;
        v = t;
    }
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
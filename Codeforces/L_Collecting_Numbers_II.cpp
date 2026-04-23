// Author:  Rajesh Biswas
// Date  :  23.10.2024

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
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n + 5), t(n + 5);
    f(i, 0, n)
    {
        cin >> t[i + 1];
        v[t[i + 1]] = i + 1;
    }
    ll x = n + 1, cnt = 0;
    f(i, 1, n + 1)
    {
        // dbg(v[i]);
        if (x > v[i])
            cnt++;
        x = v[i];
    }
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        if (t[a] > t[b])
            cnt--;
        else
            cnt++;
        cout << cnt;
        nl;
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
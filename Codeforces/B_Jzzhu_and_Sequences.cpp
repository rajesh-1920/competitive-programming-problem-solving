// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  14.01.2025

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
inline ll mod(ll n)
{
    n = n - ((n / MOD) * MOD);
    if (n < 0)
        n += MOD;
    return n;
}
void solve(void)
{
    ll n, x, y;
    cin >> x >> y >> n;
    vector<ll> v(6);
    v[0] = mod(x - y);
    v[1] = mod(x);
    v[2] = mod(y);
    v[3] = mod(y - x);
    v[4] = mod(-x);
    v[5] = mod(-y);
    n %= 6;
    cout << v[n];
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
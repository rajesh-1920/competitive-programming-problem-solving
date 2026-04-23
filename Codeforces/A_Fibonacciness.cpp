// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  19.01.2025

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
void solve(void)
{
    ll mx = 0;
    vector<ll> v(5);
    cin >> v[0] >> v[1] >> v[3] >> v[4];
    for (ll i = -100000; i <= 100000; i++)
    {
        ll cnt = 0;
        if (i == v[0] + v[1])
            cnt++;
        if (v[3] == i + v[1])
            cnt++;
        if (v[4] == i + v[3])
            cnt++;
        mx = max(cnt, mx);
    }
    cout << mx << '\n';
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
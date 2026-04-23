// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  12.01.2025

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
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto &it : a)
        cin >> it;
    for (auto &it : b)
        cin >> it;
    ll need = 0, fl = 0;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] < b[i])
        {
            fl++;
            need = max(need, b[i] - a[i]);
        }
        if (fl == 2)
        {
            cout << "NO\n";
            return;
        }
    }
    for (ll i = 0; i < n; i++)
    {
        if (a[i] >= b[i])
            a[i] -= need;
        else
            a[i] += need;
    }
    for (ll i = 0; i < n; i++)
    {
        if (a[i] < b[i])
        {
            // dbg(a[i]);
            // dbg(b[i]);
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
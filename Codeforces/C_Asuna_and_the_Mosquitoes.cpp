// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  06.06.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
#define int long long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int n;
    cin >> n;
    vector<int> ev, odd;
    while (n--)
    {
        int x;
        cin >> x;
        if (x & 1)
            odd.push_back(x);
        else
            ev.push_back(x);
    }
    sort(all(ev)), sort(all(odd));
    int ans = 0;
    if (ev.empty())
        ans = odd.back();
    else if (odd.empty())
        ans = ev.back();
    else
    {
        for (auto it : ev)
            ans += it;
        ev.pop_back();
        ans += odd.back(), odd.pop_back();
        if (!odd.empty())
            ans += odd.back() - 1, odd.pop_back();
        for (auto it : odd)
            ans += (it - 1);
    }
    cout << ans << '\n';
}
//-----------------------------------------------------------------------------------------
signed main()
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
// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  25.03.2025

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
    int n, x, od = 0, ev = 0;
    cin >> n >> x;
    vector<int> v(n);
    for (auto &it : v)
    {
        cin >> it;
        if (it & 1)
            od++;
        else
            ev++;
    }
    if (od == 0)
    {
        cout << "No\n";
        return;
    }
    if (x & 1)
    {
        od--;
        x--;
        od /= 2;
        ev /= 2;
        x /= 2;
        if (od + ev >= x)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    else
    {
        if (ev == 0)
        {
            cout << "No\n";
            return;
        }
        od--;
        ev--;
        x--;
        x--;
        od /= 2;
        ev /= 2;
        x /= 2;
        if (od + ev >= x)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
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
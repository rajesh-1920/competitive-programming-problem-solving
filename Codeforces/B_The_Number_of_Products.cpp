// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  09.08.2025

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
//------------------------------(solve)----------------------------------------------------
void solve(void)
{
    int n;
    cin >> n;
    vector<int> v(n), neg(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (i)
            neg[i] = neg[i - 1];
        if (v[i] < 0)
            neg[i]++;
    }
    int anev = 0, ev = 0, od = 0, odd = 0, evv = 0, anod = 0;
    for (int i = 0; i < n; i++)
        if (neg[i] & 1)
            od++, odd++;
        else
            ev++, evv++;
    for (int i = 0; i < n; i++)
    {
        if (v[i] < 0)
        {
            if (neg[i] & 1)
                anev += ev, anod += od;
            else
                anev += od, anod += ev;
        }
        else
        {
            if (neg[i] & 1)
                anev += od, anod += ev;
            else
                anev += ev, anod += od;
        }

        if (neg[i] & 1)
            od--, odd--;
        else
            ev--, evv--;
    }
    cout << anod << ' ' << anev << '\n';
}
//-----------------------------------------------------------------------------------------
signed main()
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
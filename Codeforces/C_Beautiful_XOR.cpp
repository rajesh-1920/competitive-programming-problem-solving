// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  17.10.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
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
void solve()
{
    int a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << 0 << "\n";
        return;
    }
    int x = a ^ b;
    if (x <= a)
    {
        cout << 1 << "\n";
        cout << x << "\n";
        return;
    }
    if (a < b)
    {
        cout << -1 << '\n';
        return;
    }
    vector<int> va, vb;
    int xa = a;
    while (xa)
    {
        if (xa & 1)
            va.push_back(1);
        else
            va.push_back(0);
        xa /= 2;
    }
    xa = b;
    while (vb.size() < va.size())
    {
        if (xa & 1)
            vb.push_back(1);
        else
            vb.push_back(0);
        xa /= 2;
    }
    vector<int> ans;
    xa = 1;
    for (int i = 0; i < va.size(); i++)
    {
        if (va[i] != vb[i])
            ans.push_back(xa);
        xa *= 2;
    }
    cout << ans.size() << '\n';
    for (auto it : ans)
        cout << it << ' ';
    cout << '\n';
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
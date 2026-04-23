// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  06.01.2025

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
const int N = 3e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    sort(all(v));
    int dis = 0;
    for (int i = 1; i < n; i++)
        dis = max(dis, (v[i] - v[i - 1]));

    if (v.front() > 0 && v.back() < d)
    {
        int mx = max(v.front(), (d - v.back()));
        if (dis > 2 * mx)
        {
            cout << (dis / 2) << ((dis & 1) == 1 ? ".5000" : ".0000");
        }
        else
            cout << mx << ".0000";
    }
    else if (v.back() < d)
    {
        int mx = (d - v.back());
        if (dis > 2 * mx)
        {
            cout << (dis / 2) << ((dis & 1) == 1 ? ".5000" : ".0000");
        }
        else
            cout << mx << ".0000";
    }
    else if (v.front() > 0)
    {
        int mx = v.front();
        if (dis > 2 * mx)
        {
            cout << (dis / 2) << ((dis & 1) == 1 ? ".5000" : ".0000");
        }
        else
            cout << mx << ".0000";
    }
    else
        cout << (dis / 2) << ((dis & 1) == 1 ? ".5000" : ".0000");
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
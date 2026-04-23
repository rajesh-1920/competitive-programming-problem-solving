// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  29.04.2025

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
const int MOD = 1e5 + 7;
int N = 1e6;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int xs, ys, xt, yt, xp, yp;
    cin >> xs >> ys >> xt >> yt >> xp >> yp;
    vector<pair<int, int>> vp;
    if (xt > xs)
    {
        if (yt > ys)
        {
            if (xp > xs)
            {
                vp.push_back({-N, ys});
                vp.push_back({-N, N});
                if (xt > xp)
                    vp.push_back({N, N});
            }
            else
            {
                vp.push_back({N, ys});
                vp.push_back({N, N});
                if (xt < xp)
                    vp.push_back({-N, N});
            }
        }
        else
        {
            if (xp > xs)
            {
                vp.push_back({-N, ys});
                vp.push_back({-N, -N});
                if (xt > xp)
                    vp.push_back({N, -N});
            }
            else
            {
                vp.push_back({N, ys});
                vp.push_back({N, -N});
                if (xt < xp)
                    vp.push_back({-N, -N});
            }
        }
    }
    else
    {
        if (yt > ys)
        {
            if (xp > xs)
            {
                vp.push_back({-N, ys});
                vp.push_back({-N, N});
                if (xt > xp)
                    vp.push_back({N, N});
            }
            else
            {
                vp.push_back({N, ys});
                vp.push_back({N, N});
                if (xt < xp)
                    vp.push_back({-N, N});
            }
        }
        else
        {
            if (xp > xs)
            {
                vp.push_back({-N, ys});
                vp.push_back({-N, -N});
                if (xt > xp)
                    vp.push_back({N, -N});
            }
            else
            {
                vp.push_back({N, ys});
                vp.push_back({N, -N});
                if (xt < xp)
                    vp.push_back({-N, -N});
            }
        }
    }
    cout << vp.size() << '\n';
    for (auto it : vp)
        cout << it.fi << ' ' << it.sc << '\n';
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
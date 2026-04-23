// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  05.05.2025

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
const int inf = 1e18 + 7;
const int MOD = 1e9 + 7;
const int N = 2e3 + 10;
//-----------------------------------------------------------------------------------------
vector<int> tt[N];
void build(vector<int> &v)
{
    for (int i = 0; i <= v.size(); i++)
    {
        tt[i].clear();
        if (i == v.size())
        {
            for (int j = 0; j < v.size(); j++)
                tt[i].push_back(v[j]);
            tt[i].push_back(tt[i].back() + 1);
        }
        else if (i == 0)
        {
            tt[i].push_back(v[i] - 1);
            for (int j = 0; j < v.size(); j++)
                tt[i].push_back(v[j]);
        }
        else
        {
            for (int j = 0; j < v.size(); j++)
            {
                if (i == j)
                {
                    if (tt[i].size() & 1)
                        tt[i].push_back(tt[i].back() + 1);
                    else
                        tt[i].push_back(v[j] - 1);
                }
                tt[i].push_back(v[j]);
            }
        }
    }
}
bool ok(vector<int> &v, int val)
{
    if (v.size() & 1)
    {
        for (int i = 0; i <= v.size(); i++)
        {
            int fl = 1;
            for (int j = 1; j < tt[i].size(); j += 2)
            {
                if (tt[i][j] == tt[i][j - 1] || tt[i][j] - tt[i][j - 1] > val)
                {
                    fl = 0;
                    break;
                }
            }
            if (fl)
                return true;
        }
        return false;
    }
    else
    {
        for (int i = 1; i < v.size(); i += 2)
        {
            if (v[i] == v[i - 1] || v[i] - v[i - 1] > val)
                return false;
        }
        return true;
    }
}
void solve(void)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    sort(all(v));
    if (n & 1)
        build(v);
    int ans = inf, l = 1, r = inf;
    while (l <= r)
    {
        int m = (r + l) / 2;
        if (ok(v, m))
            ans = min(ans, m), r = m - 1;
        else
            l = m + 1;
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

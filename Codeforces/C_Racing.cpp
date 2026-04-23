// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  16.06.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
#define fi first
#define sc second
#define int long long int
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int n;
    cin >> n;
    vector<int> d(n);
    for (auto &it : d)
        cin >> it;
    vector<pair<int, int>> vp(n);
    for (auto &it : vp)
        cin >> it.fi >> it.sc;
    vector<int> next(n), hate;
    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        if (d[i] == -1)
            hate.push_back(i);
        else
            curr += d[i];
        while (curr < vp[i].fi)
        {
            if (hate.empty())
            {
                cout << -1 << '\n';
                return;
            }
            d[hate.back()] = 1;
            curr++;
            hate.pop_back();
        }
        if (curr > vp[i].sc or curr < vp[i].fi)
        {
            cout << -1 << '\n';
            return;
        }
    }
    curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr += d[i] == 1;
        if (curr > vp[i].sc or curr < vp[i].fi)
        {
            cout << -1 << '\n';
            return;
        }
    }
    for (auto it : d)
        cout << max(0ll, it) << ' ';
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
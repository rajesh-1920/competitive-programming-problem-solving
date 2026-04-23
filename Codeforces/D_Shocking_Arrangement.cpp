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
void solve(void)
{
    int n, mx = 0, mn = inf, z = 0;
    cin >> n;
    vector<int> pos, neg;
    for (int i = 0, it; i < n; i++)
    {
        cin >> it, mx = max(mx, it), mn = min(mn, it);
        if (it > 0)
            pos.push_back(it);
        else if (it < 0)
            neg.push_back(it);
        else
            z++;
    }
    while (z--)
        if (pos.size() < neg.size())
            pos.push_back(0);
        else
            neg.push_back(0);
    vector<int> temp;
    sort(all(pos));
    sort(rall(neg));
    int fl = 0;
    while (temp.size() < n)
    {
        if (fl)
        {
            if (pos.size())
                temp.push_back(pos.back()), pos.pop_back();
        }
        else if (neg.size())
            temp.push_back(neg.back()), neg.pop_back();
        fl ^= 1;
    }
    for (auto it : temp)
        cout << it << ' 3';
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
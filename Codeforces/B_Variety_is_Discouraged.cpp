// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  16.02.2025

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
    vector<int> v(n);
    map<int, int> mp, cnt1;

    for (auto &it : v)
    {
        cin >> it;
        mp[it]++;
    }
    for (auto it : mp)
        if (it.sc == 1)
            cnt1[it.fi] = 1;
    int ans = 0, al = 0, ar = 0, l = -1, r = -1;
    for (int i = 0; i < n; i++)
    {
        if (cnt1.find(v[i]) != cnt1.end())
        {
            if (l == -1)
            {
                l = i + 1;
                r = i + 1;
            }
            else
                r = i + 1;
            if (ans < (r - l + 1))
            {
                ans = r - l + 1;
                al = l;
                ar = r;
            }
        }
        else
            l = -1;
    }
    if (ans == 0)
        cout << 0 << '\n';
    else
        cout << al << ' ' << ar << '\n';
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
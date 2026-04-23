// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  28.08.2025

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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;

    int ans = 0, p1 = 0, p2 = 0;
    while (p2 < n)
    {
        if (v[p2] == 2 && v[p1] == 1)
        {
            int lc0 = 1, mc0 = 0, rc0 = 1;
            for (int i = p1 + 1; i < p2; i++)
                if (v[i])
                {
                    mc0 = -1;
                    break;
                }
                else
                    mc0++;
            if (mc0 == -1)
            {
                p1++;
                continue;
            }
            for (int i = p2 + 1; i < n; i++)
                if (v[i])
                    break;
                else
                    rc0++;
            for (int i = p1 - 1; i >= 0; i--)
                if (v[i])
                    break;
                else
                    lc0++;
            ans += rc0 * lc0;
            if (mc0 == 0)
                ans--;
            p1++, p2++;
        }
        else if (v[p2] == 2 && p1 < p2)
            p1++;
        else
            p2++;
    }

    p1 = p2 = 0;
    while (p2 < n)
    {
        if (v[p2] == 1 && v[p1] == 2)
        {
            int lc0 = 1, mc0 = 0, rc0 = 1;
            for (int i = p1 + 1; i < p2; i++)
                if (v[i])
                {
                    mc0 = -1;
                    break;
                }
                else
                    mc0++;
            if (mc0 == -1)
            {
                p1++;
                continue;
            }
            for (int i = p2 + 1; i < n; i++)
                if (v[i])
                    break;
                else
                    rc0++;
            for (int i = p1 - 1; i >= 0; i--)
                if (v[i])
                    break;
                else
                    lc0++;
            ans += rc0 * lc0;
            if (mc0 == 0)
                ans--;
            p1++, p2++;
        }
        else if (v[p2] == 1 && p1 < p2)
            p1++;
        else
            p2++;
    }
    p1 = p2 = 0;
    while (p2 < n)
    {
        if (v[p2] == 1 && v[p1] == 1 && p1 != p2)
        {
            int lc0 = 1, mc0 = 0, rc0 = 1;
            for (int i = p1 + 1; i < p2; i++)
                if (v[i])
                {
                    mc0 = -1;
                    break;
                }
                else
                    mc0++;
            if (mc0 == -1)
            {
                p1++;
                continue;
            }
            for (int i = p2 + 1; i < n; i++)
                if (v[i])
                    break;
                else
                    rc0++;
            for (int i = p1 - 1; i >= 0; i--)
                if (v[i])
                    break;
                else
                    lc0++;
            ans += rc0 * lc0;
            if (mc0 == 0)
                ans--;
            p1++, p2++;
        }
        else if (v[p2] == 1 && p1 < p2)
            p1++;
        else
            p2++;
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
    // cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}
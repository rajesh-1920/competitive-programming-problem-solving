// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  10.05.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << ' '
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
    int n, k;
    cin >> n >> k;
    vector<int> v(n), ind(k);
    for (auto &it : v)
        cin >> it;
    for (auto &it : ind)
        cin >> it, it--;
    int ans = 0, ls = 0, x = v[ind.front()];
    for (int i = 0; i + 1 < k; i++)
    {
        int l = ind[i], r = ind[i];
        while (l != ls && v[l] == x)
            l--;
        while (r + 1 < ind[i + 1] && v[r] == x)
            r++;
        while (l != ls)
        {
            while (r + 1 < ind[i + 1] && l != ls && v[r] == v[l])
                r++, l--;
            if (ls != l)
                l--;
        }
        while (r + 1 < ind[i + 1] && v[r] == v[l])
            r++;
        int cnt = 0;
        for (int j = ls; j <= ind[i]; j++)
        {
            if (j + 1 < ind[i] && v[j] == v[j + 1])
                continue;
            if (v[j] == x && cnt & 1)
                cnt++;
            else if (v[j] != x && cnt % 2 == 0)
                cnt++;
        }
        ans += cnt;
        ls = r;
    }
    {
        int cnt = 0, cn = 0;
        for (int j = ls; j <= ind.back(); j++)
        {
            if (j + 1 < ind.back() && v[j] == v[j + 1])
                continue;
            if (v[j] == x && cnt & 1)
                cnt++;
            else if (v[j] != x && cnt % 2 == 0)
                cnt++;
        }
        for (int j = n - 1; j >= ind.back(); j--)
        {
            if (j - 1 > ind.back() && v[j] == v[j - 1])
                continue;
            if (v[j] == x && cn & 1)
                cn++;
            else if (v[j] != x && cn % 2 == 0)
                cn++;
        }
        ans += max(cnt, cn);
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
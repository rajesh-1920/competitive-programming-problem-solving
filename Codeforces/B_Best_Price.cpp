// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  12.05.2025

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
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.sc == b.sc)
        return a.fi > b.fi;
    return a.sc > b.sc;
}
void solve(void)
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n), t(n);
    vector<pair<int, int>> pos(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        pos[i] = {v[i], i};
    }
    int to = 0;
    for (auto &it : t)
    {
        cin >> it;
        to += it;
    }
    sort(all(pos));
    for (auto it : v)
        t.push_back(it);
    sort(all(t));

    int ans = 0, i = 0, s = 0;
    for (auto it : t)
    {
        while (i < v.size())
        {
            if (v[i] > it)
                break;
            s += v[i];
            to -= t[pos[i].sc];
            i++;
        }
        if (i <= k)
            ans = max(ans, s + to);
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
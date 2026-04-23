// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  20.01.2026

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
const int N = 1e6 + 10;
//------------------------------(solve)----------------------------------------------------
struct stc
{
    int l, r, ind;
};
void solve(void)
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n), ans(m, 0);
    int len = sqrt(n) + 1;
    for (auto &it : v)
        cin >> it;
    vector<stc> qre;
    for (int i = 0, x, y; i < m; i++)
    {
        cin >> x >> y;
        qre.push_back({x - 1, y - 1, i});
    }
    sort(all(qre), [len](const stc &a, const stc &b)
         {
        if(a.l/len==b.l/len)
        return a.r>b.r;
        return a.l/len<b.l/len; });

    int cans = 0, curr = -1, curl = 0;
    vector<int> mp(N, 0);
    for (auto &it : qre)
    {
        while (curr < it.r)
        {
            curr++;
            cans -= (v[curr] * mp[v[curr]] * mp[v[curr]]);
            mp[v[curr]]++;
            cans += (v[curr] * mp[v[curr]] * mp[v[curr]]);
        }
        while (curl > it.l)
        {
            curl--;
            cans -= (v[curl] * mp[v[curl]] * mp[v[curl]]);
            mp[v[curl]]++;
            cans += (v[curl] * mp[v[curl]] * mp[v[curl]]);
        }
        while (curl < it.l)
        {
            cans -= (v[curl] * mp[v[curl]] * mp[v[curl]]);
            mp[v[curl]]--;
            cans += (v[curl] * mp[v[curl]] * mp[v[curl]]);
            curl++;
        }
        while (curr > it.r)
        {
            cans -= (v[curr] * mp[v[curr]] * mp[v[curr]]);
            mp[v[curr]]--;
            cans += (v[curr] * mp[v[curr]] * mp[v[curr]]);
            curr--;
        }
        ans[it.ind] = cans;
    }
    for (auto &it : ans)
        cout << it << '\n';
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
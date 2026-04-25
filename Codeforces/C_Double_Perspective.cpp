// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  25.04.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
#define fi first
#define sc second
#define int long long int

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int MOD = 1e9 + 7;
const int N = 1e6 + 1;

//-----------------------------------------------------------------------------------------
int parr(int a, vector<int> &par)
{
    if (par[a] == a)
        return a;
    return par[a] = parr(par[a], par);
}
void solve(void)
{
    int n;
    cin >> n;
    priority_queue<pair<pair<int, int>, pair<int, int>>> pq;
    vector<int> par(2 * n + 10), ans;
    for (int i = 1, x, y; i <= n; i++)
    {
        cin >> x >> y;
        pq.push({{y - x, i}, {x, y}});
    }
    for (int i = 1; i < 2 * n + 10; i++)
        par[i] = i;
    while (!pq.empty())
    {
        int vl = pq.top().fi.fi, i = pq.top().fi.sc;
        int a = parr(pq.top().sc.fi, par), b = parr(pq.top().sc.sc, par);
        if (a != b)
        {
            par[b] = a;
            ans.push_back(i);
        }
        pq.pop();
    }
    sort(all(ans));
    cout << ans.size() << '\n';
    for (auto &it : ans)
        cout << it << ' ';
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
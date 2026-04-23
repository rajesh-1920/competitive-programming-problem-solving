// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  13.11.2025

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
void dfs(int n, int &time, vector<int> &in, vector<int> &out, vector<int> &aul, vector<vector<int>> const &v)
{
    in[n] = ++time;
    aul.push_back(n);
    for (auto it : v[n])
    {
        if (in[it] == -1)
            dfs(it, time, in, out, aul, v);
    }
    out[n] = time;
}
void init(int nd, int l, int r, vector<int> &seg_tree, vector<int> const &col, vector<int> const &aul)
{
    if (l == r)
    {
        seg_tree[nd] = (1LL << col[aul[l]]);
        return;
    }
    int mid = (l + r) / 2;
    init(nd * 2, l, mid, seg_tree, col, aul);
    init(nd * 2 + 1, mid + 1, r, seg_tree, col, aul);
    seg_tree[nd] = (seg_tree[nd * 2] | seg_tree[nd * 2 + 1]);
}
int value(int nd, int l, int r, int const &myl, int const &myr, vector<int> &seg_tree, vector<int> &lazy)
{
    if (lazy[nd])
    {
        seg_tree[nd] = lazy[nd];
        if (l != r)
        {
            lazy[nd * 2] = lazy[nd];
            lazy[nd * 2 + 1] = lazy[nd];
        }
        lazy[nd] = 0;
    }
    if (l > r || l > myr || r < myl)
        return 0;
    if (l >= myl && r <= myr)
        return seg_tree[nd];
    int mid = (l + r) / 2;
    return (value(nd * 2, l, mid, myl, myr, seg_tree, lazy) |
            value(nd * 2 + 1, mid + 1, r, myl, myr, seg_tree, lazy));
}
void update(int nd, int l, int r, int const &myl, int const &myr, int const &val, vector<int> &seg_tree, vector<int> &lazy)
{
    if (lazy[nd])
    {
        seg_tree[nd] = lazy[nd];
        if (l != r)
        {
            lazy[nd * 2] = lazy[nd];
            lazy[nd * 2 + 1] = lazy[nd];
        }
        lazy[nd] = 0;
    }
    if (l > r || l > myr || r < myl)
        return;
    if (l >= myl && r <= myr)
    {
        seg_tree[nd] = (1LL << val);
        if (l != r)
        {
            lazy[nd * 2] = (1LL << val);
            lazy[nd * 2 + 1] = (1LL << val);
        }
        return;
    }
    int mid = (l + r) / 2;
    update(nd * 2, l, mid, myl, myr, val, seg_tree, lazy);
    update(nd * 2 + 1, mid + 1, r, myl, myr, val, seg_tree, lazy);
    seg_tree[nd] = (seg_tree[nd * 2] | seg_tree[nd * 2 + 1]);
}
void solve(void)
{
    int n, m;
    cin >> n >> m;
    vector<int> col(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> col[i];
    vector<vector<int>> v(n + 1);
    for (int i = 1, x, y; i < n; i++)
    {
        cin >> x >> y;
        v[x].push_back(y), v[y].push_back(x);
    }
    vector<int> in(n + 1, -1), out(n + 1), aul;
    aul.push_back(0);
    int time = 0;
    dfs(1, time, in, out, aul, v);
    vector<int> seg_tree(4 * n + 10), lazy(4 * n + 10, 0);
    init(1, 1, n, seg_tree, col, aul);
    while (m--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int u, x;
            cin >> u >> x;
            update(1, 1, n, in[u], out[u], x, seg_tree, lazy);
        }
        else
        {
            int x;
            cin >> x;
            x = value(1, 1, n, in[x], out[x], seg_tree, lazy);
            cout << __builtin_popcountll(x) << '\n';
        }
    }
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
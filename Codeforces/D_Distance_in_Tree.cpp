// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  07.01.2026

#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 5e4 + 10;
const int LOG = 15;
//-----------------------------------------------------------------------------------------
long long neutral_value = 0;
long long merge_op(long long a, long long b)
{
    return a + b; // SUM
}
long long apply_op(long long nodeVal, long long lazyVal, int len)
{
    return nodeVal + lazyVal * len; // ADD operation for SUM
}
long long lazy_op_comb(long long oldLazy, long long newLazy)
{
    return oldLazy + newLazy; // ADD
}
vector<int> adj[N];
int parent[N][LOG], depth[N], heavy[N], head[N], pos[N], sz[N];
int cur_pos, base[N], seg[4 * N], lazy[4 * N]; // edge values stored at deeper node
struct Edge
{
    int u, v, w;
};
vector<Edge> edges; // input edges

int dfs(int v, int p)
{
    parent[v][0] = p;
    depth[v] = (p == 0 ? 0 : depth[p] + 1);
    sz[v] = 1, heavy[v] = 0;
    int maxsz = 0;
    for (int c : adj[v])
    {
        if (c == p)
            continue;
        int sub = dfs(c, v);
        sz[v] += sub;
        if (sub > maxsz)
            maxsz = sub, heavy[v] = c;
    }
    return sz[v];
}
void decompose(int v, int h)
{
    head[v] = h, pos[v] = ++cur_pos;
    base[cur_pos] = neutral_value; // will assign edge weights later
    if (heavy[v])
        decompose(heavy[v], h);
    for (int c : adj[v])
    {
        if (c == parent[v][0] || c == heavy[v])
            continue;
        decompose(c, c);
    }
}
void build_lca(int n)
{
    for (int v = 1; v <= n; v++)
        for (int k = 1; k < LOG; k++)
            parent[v][k] = parent[parent[v][k - 1]][k - 1];
}
int LCA(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    int d = depth[a] - depth[b];
    for (int k = 0; k < LOG; k++)
        if (d & (1 << k))
            a = parent[a][k];
    if (a == b)
        return a;
    for (int k = LOG - 1; k >= 0; k--)
        if (parent[a][k] != parent[b][k])
            a = parent[a][k], b = parent[b][k];
    return parent[a][0];
}
void push(int idx, int l, int r)
{
    if (lazy[idx] == 0)
        return;
    seg[idx] = apply_op(seg[idx], lazy[idx], r - l + 1);
    if (l != r)
    {
        lazy[idx * 2] = lazy_op_comb(lazy[idx * 2], lazy[idx]);
        lazy[idx * 2 + 1] = lazy_op_comb(lazy[idx * 2 + 1], lazy[idx]);
    }
    lazy[idx] = 0;
}
void build_seg(int idx, int l, int r)
{
    if (l == r)
    {
        seg[idx] = base[l];
        return;
    }
    int mid = (l + r) / 2;
    build_seg(idx * 2, l, mid);
    build_seg(idx * 2 + 1, mid + 1, r);
    seg[idx] = merge_op(seg[idx * 2], seg[idx * 2 + 1]);
}
void update_range(int idx, int l, int r, int ql, int qr, long long val)
{
    push(idx, l, r);
    if (qr < l || r < ql)
        return;
    if (ql <= l && r <= qr)
    {
        lazy[idx] = lazy_op_comb(lazy[idx], val);
        push(idx, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update_range(idx * 2, l, mid, ql, qr, val);
    update_range(idx * 2 + 1, mid + 1, r, ql, qr, val);
    seg[idx] = merge_op(seg[idx * 2], seg[idx * 2 + 1]);
}
long long query_range(int idx, int l, int r, int ql, int qr)
{
    if (qr < l || r < ql)
        return neutral_value;
    push(idx, l, r);
    if (ql <= l && r <= qr)
        return seg[idx];
    int mid = (l + r) / 2;
    return merge_op(query_range(idx * 2, l, mid, ql, qr),
                    query_range(idx * 2 + 1, mid + 1, r, ql, qr));
}
long long query_path(int u, int v)
{
    long long res = neutral_value;
    while (head[u] != head[v])
    {
        if (depth[head[u]] < depth[head[v]])
            swap(u, v);
        res = merge_op(res, query_range(1, 1, cur_pos, pos[head[u]], pos[u]));
        u = parent[head[u]][0];
    }
    if (u == v)
        return res;
    if (depth[u] > depth[v])
        swap(u, v);
    res = merge_op(res, query_range(1, 1, cur_pos, pos[u] + 1, pos[v]));
    return res;
}
void update_path(int u, int v, long long val)
{
    while (head[u] != head[v])
    {
        if (depth[head[u]] < depth[head[v]])
            swap(u, v);
        update_range(1, 1, cur_pos, pos[head[u]], pos[u], val);
        u = parent[head[u]][0];
    }
    if (u == v)
        return;
    if (depth[u] > depth[v])
        swap(u, v);
    update_range(1, 1, cur_pos, pos[u] + 1, pos[v], val);
}
void update_edge(int u, int v, long long val)
{
    int deeper = (depth[u] > depth[v] ? u : v);
    update_range(1, 1, cur_pos, pos[deeper], pos[deeper], val);
}
void assign_initial_edge_values()
{
    for (auto &e : edges)
    {
        int deeper = (depth[e.u] > depth[e.v] ? e.u : e.v);
        base[pos[deeper]] = e.w;
    }
}
//-----------------------------------------------------------------------------------------
void solve(void)
{
    edges.clear();
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
        heavy[i] = 0;
        for (int k = 0; k < LOG; k++)
            parent[i][k] = 0;
        base[i] = neutral_value;
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        long long w = 1;
        cin >> u >> v; // read edge
        adj[u].push_back(v), adj[v].push_back(u);
        edges.push_back({u, v, w});
    }
    dfs(1, 0), build_lca(n);
    cur_pos = 0;
    decompose(1, 1), assign_initial_edge_values();
    build_seg(1, 1, cur_pos);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (query_path(i, j) == k)
                ans++;
        }
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
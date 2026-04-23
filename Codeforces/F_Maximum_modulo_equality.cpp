// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  19.10.2025

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
struct Node
{
    int mn, second_mn;
};

struct SegTree
{
    // gpt generated tree code
    int n;
    vector<Node> tree;

    SegTree(const vector<int> &a)
    {
        n = a.size();
        tree.resize(4 * n);
        build(a, 1, 0, n - 1);
    }

    Node merge(Node left, Node right)
    {
        vector<int> vals = {left.mn, left.second_mn, right.mn, right.second_mn};
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        Node res;
        res.mn = vals[0];
        res.second_mn = (vals.size() > 1 ? vals[1] : INT_MAX);
        return res;
    }

    void build(const vector<int> &a, int node, int l, int r)
    {
        if (l == r)
        {
            tree[node] = {a[l], INT_MAX};
            return;
        }
        int mid = (l + r) / 2;
        build(a, node * 2, l, mid);
        build(a, node * 2 + 1, mid + 1, r);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr)
    {
        if (qr < l || ql > r)
            return {INT_MAX, INT_MAX};
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) / 2;
        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);
        return merge(left, right);
    }

    int rangeSecondMin(int L, int R)
    {
        Node ans = query(1, 0, n - 1, L, R);
        return (ans.second_mn == INT_MAX ? -1 : ans.second_mn);
    }
};
void init(int nd, int l, int r, vector<int> &v, vector<int> &tree)
{
    if (l == r)
    {
        tree[nd] = v[l];
        return;
    }
    int mid = (l + r) / 2;
    init(nd * 2, l, mid, v, tree);
    init(nd * 2 + 1, mid + 1, r, v, tree);
    tree[nd] = min(tree[nd * 2], tree[nd * 2 + 1]);
}
int value(int nd, int l, int r, int &myl, int &myr, vector<int> &tree)
{
    if (l > r || l > myr || r < myl)
        return INT_MAX;
    if (l >= myl && r <= myr)
        return tree[nd];
    int mid = (l + r) / 2;
    return min(value(nd * 2, l, mid, myl, myr, tree),
               value(nd * 2 + 1, mid + 1, r, myl, myr, tree));
}
void solve(void)
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n), tree(4 * n);
    for (auto &it : v)
        cin >> it;
    SegTree seg(v);
    init(1, 0, n - 1, v, tree);
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int x = seg.rangeSecondMin(l, r);
        int y = value(1, 0, n - 1, l, r, tree);
        int t = x - y;
        if (t <= 0)
            t = 0;
        while (t && x % t != y % t)
            t /= 2;
        cout << t << ' ';
    }
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
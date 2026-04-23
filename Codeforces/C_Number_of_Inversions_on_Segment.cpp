// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  16.01.2026

#include <bits/stdc++.h>
using namespace std;
#define int long long int
struct stc
{
    int inv;
    vector<int> cnt;
};
void init(int n, int l, int r, vector<stc> &tree, vector<int> &v)
{
    if (l == r)
    {
        tree[n].cnt[v[l]]++;
        return;
    }
    int m = (l + r) / 2;
    init(2 * n, l, m, tree, v);
    init(2 * n + 1, m + 1, r, tree, v);
    tree[n].inv += tree[2 * n].inv + tree[2 * n + 1].inv;
    for (int i = 40; i >= 1; i--)
    {
        tree[n].cnt[i] += (tree[n * 2].cnt[i] + tree[n * 2 + 1].cnt[i]);
        if (tree[n * 2].cnt[i])
            for (int j = 1; j < i; j++)
                tree[n].inv += (tree[n * 2 + 1].cnt[j] * tree[n * 2].cnt[i]);
    }
}
stc query(int n, int l, int r, int &myl, int &myr, vector<stc> &tree)
{
    vector<int> temp(45, 0);
    if (l > r || l > myr || r < myl)
        return {0, temp};
    if (l >= myl && r <= myr)
        return tree[n];

    int m = (l + r) / 2;
    stc t1 = query(2 * n, l, m, myl, myr, tree);
    stc t2 = query(2 * n + 1, m + 1, r, myl, myr, tree);
    int fl = 1;
    int ans = t1.inv + t2.inv;
    for (int i = 40; i >= 1; i--)
    {
        temp[i] += (t1.cnt[i] + t2.cnt[i]);
        if (t1.cnt[i])
            for (int j = 1; j < i; j++)
                ans += (t2.cnt[j] * t1.cnt[i]);
    }
    return {ans, temp};
}
void update(int n, int l, int r, int &myl, int &myr, int &myval, vector<stc> &tree, vector<int> &v)
{
    if (l > r || l > myl || r < myr)
        return;
    if (l >= myl && r <= myr)
    {
        tree[n].cnt[v[l]]--;
        tree[n].cnt[myval]++;
        tree[n].inv = 0;
        v[l] = myval;
        return;
    }

    int m = (l + r) / 2;
    for (int i = 0; i < tree[n].cnt.size(); i++)
        tree[n].cnt[i] = 0;
    update(2 * n, l, m, myl, myr, myval, tree, v);
    update(2 * n + 1, m + 1, r, myl, myr, myval, tree, v);
    tree[n].inv = tree[2 * n].inv + tree[n * 2 + 1].inv;
    for (int i = 40; i >= 1; i--)
    {
        tree[n].cnt[i] += (tree[n * 2].cnt[i] + tree[n * 2 + 1].cnt[i]);
        if (tree[n * 2].cnt[i])
            for (int j = 1; j < i; j++)
                tree[n].inv += (tree[n * 2 + 1].cnt[j] * tree[n * 2].cnt[i]);
    }
}
void solve(void)
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1);
    vector<stc> tree(4 * n + 10, {0, vector<int>(45, 0)});
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    init(1, 1, n, tree, v);
    while (q--)
    {
        int tp, x, y;
        cin >> tp >> x >> y;
        if (tp == 1)
            cout << query(1, 1, n, x, y, tree).inv << '\n';
        else
            update(1, 1, n, x, x, y, tree, v);
    }
}
signed main()
{
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

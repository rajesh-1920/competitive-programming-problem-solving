#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
class Solution
{
// cout << fixed << showpoint << setprecision(10);
#define dbg(x) cout << #x << " = " << x << '\n'

    void init(int nd, int l, int r, vector<pair<int, int>> &v, vector<int> &tree)
    {
        if (l == r)
        {
            tree[nd] = v[l - 1].second;
            return;
        }
        int mid = (l + r) / 2;
        init(nd * 2, l, mid, v, tree);
        init(nd * 2 + 1, mid + 1, r, v, tree);
        tree[nd] = min(tree[nd * 2], tree[nd * 2 + 1]);
    }
    void update(int nd, int l, int r, int &myl, int &myr, vector<int> &tree)
    {
        if (l > r || l > myr || r < myl)
            return;
        if (l >= myl && r <= myr)
        {
            tree[nd] = INT_MAX;
            return;
        }
        int mid = (l + r) / 2;
        update(nd * 2, l, mid, myl, myr, tree);
        update(nd * 2 + 1, mid + 1, r, myl, myr, tree);
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

public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        int N = 4e5 + 10;
        int n = fruits.size();
        vector<int> tree(N, INT_MAX);
        vector<pair<int, int>> v;
        for (int i = 0; i < fruits.size(); i++)
            v.push_back({baskets[i], i + 1});
        sort(v.begin(), v.end());
        sort(baskets.begin(), baskets.end());
        init(1, 1, v.size(), v, tree);

        vector<int> pos(n + 5, 0);
        for (int i = 0; i < n; i++)
            pos[v[i].second] = i + 1;

        int ans = fruits.size();
        for (int i = 0; i < fruits.size(); i++)
        {
            int l = 1 + lower_bound(baskets.begin(), baskets.end(), fruits[i]) - baskets.begin();
            if (l > n)
                continue;
            int tt = value(1, 1, n, l, n, tree);
            if (tt != INT_MAX)
            {
                ans--;
                tt = pos[tt];
                update(1, 1, n, tt, tt, tree);
            }
        }
        return ans;
    }
};
//-----------------------------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    {
        Solution aa;
        int n;
        cin >> n;
        vector<int> v(n), vv(n);
        for (auto &it : v)
            cin >> it;
        for (auto &it : vv)
            cin >> it;
        cout << aa.numOfUnplacedFruits(v, vv);
    }
    return 0;
}
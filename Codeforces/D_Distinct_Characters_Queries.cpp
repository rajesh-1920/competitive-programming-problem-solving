// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  07.01.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------

/*map<char, int> tree[4 * N];
void init(int n, int l, int r, string &s)
{
    if (l == r)
    {
        tree[n][s[l]]++;
        return;
    }
    int m = (l + r) / 2;
    init(2 * n, l, m, s);
    init(2 * n + 1, m + 1, r, s);
    for (auto it : tree[2 * n])
        tree[n][it.fi] += it.sc;
    for (auto it : tree[2 * n + 1])
        tree[n][it.fi] += it.sc;
}
map<char, int> query(int n, int l, int r, int &myl, int &myr)
{
    map<char, int> mp;
    if (l > r || l > myr || r < myl)
        return mp;
    if (l >= myl && r <= myr)
        return tree[n];
    int m = (l + r) / 2;
    map<char, int> left = query(2 * n, l, m, myl, myr);
    map<char, int> right = query(2 * n + 1, m + 1, r, myl, myr);
    for (auto it : left)
        right[it.fi] += it.sc;
    return right;
}

void update(int n, int l, int r, int &myl, int &myr, char &ch)
{
    if (l > r || l > myr || r < myl)
        return;
    if (l >= myl && r <= myr)
    {
        tree[n].clear();
        tree[n][ch]++;
        return;
    }
    int m = (l + r) / 2;
    update(n * 2, l, m, myl, myr, ch);
    update(n * 2 + 1, m + 1, r, myl, myr, ch);
    tree[n].clear();
    for (auto it : tree[2 * n])
        tree[n][it.fi] += it.sc;
    for (auto it : tree[2 * n + 1])
        tree[n][it.fi] += it.sc;
}
*/
void solve(void)
{
    string s;
    int q;
    cin >> s >> q;
    vector<set<int>> st(26);
    for (int i = 0; i < s.size(); i++)
        st[s[i] - 'a'].insert(i);

    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            string ss;
            cin >> x >> ss;
            // update(1, 1, n, x, x, st.front());
            x--;
            st[s[x] - 'a'].erase(x);
            s[x] = ss.front();
            st[s[x] - 'a'].insert(x);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--, r--;
            int cnt = 0;
            for (int i = 0; i < 26; i++)
                if (st[i].lower_bound(l) != st[i].end() && st[i].upper_bound(r) != st[i].begin())
                {
                    int l1 = *(st[i].lower_bound(l));
                    int r1 = *(--st[i].upper_bound(r));
                    if (l1 >= l && r1 <= r && l1 <= r1)
                        cnt++;
                                }
            cout << cnt << '\n';
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
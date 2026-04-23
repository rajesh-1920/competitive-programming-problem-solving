// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  05.01.2025

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
const int N = 3e5 + 10;
//-----------------------------------------------------------------------------------------
int tree[4 * N], a[N];
int init(int nd, int l, int r)
{
    if (l == r)
    {
        tree[nd] = a[l];
        return 1;
    }
    int md = (l + r) / 2;
    int t1 = init(nd * 2, l, md);
    int t2 = init(nd * 2 + 1, md + 1, r);
    if (t1 == 1)
    {
        tree[nd] = tree[nd * 2] | tree[nd * 2 + 1];
        return 0;
    }
    else
    {
        tree[nd] = tree[nd * 2] ^ tree[nd * 2 + 1];
        return 1;
    }
}
int update(int nd, int l, int r, int &pos, int &val)
{
    if (l == pos && r == pos)
    {
        tree[nd] = val;
        return 1;
    }
    int md = (l + r) / 2;
    int t1 = 0;
    if (pos <= md)
        t1 = update(nd * 2, l, md, pos, val);
    else
        t1 = update(nd * 2 + 1, md + 1, r, pos, val);
    if (t1 == 1)
    {
        tree[nd] = tree[nd * 2] | tree[nd * 2 + 1];
        return 0;
    }
    else
    {
        tree[nd] = tree[nd * 2] ^ tree[nd * 2 + 1];
        return 1;
    }
}
void solve(void)
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <=(1 << n); i++)
        cin >> a[i];
    int tt = init(1, 1, (1 << n));
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        tt = update(1, 1, (1 << n), x, y);
        cout << tree[1] << '\n';
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
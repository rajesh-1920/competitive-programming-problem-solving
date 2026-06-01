// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  01.06.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
struct node
{
    int l, r, idx;
};
int sz;
bool cmp(const node &a, const node &b)
{
    int A = a.l / sz, B = b.l / sz;
    if (A != B)
        return A < B;
    if (A & 1)
        return a.r > b.r;
    return a.r < b.r;
}
void solve(void)
{
    string s;
    int n;
    cin >> s >> n;
    vector<node> q(n);
    for (int i = 0; i < n; i++)
    {
        cin >> q[i].l >> q[i].r;
        q[i].l--, q[i].r--, q[i].idx = i;
    }
    sz = sqrt(s.size()) + 1;
    sort(all(q), cmp);
    vector<int> v(s.size(), 0), freq(s.size() + 10, 0), ans(n, 0);
    stack<int> stc;
    n = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            stc.push(i);
        else if (!stc.empty())
        {
            v[i] = v[stc.top()] = n++;
            stc.pop();
        }
    }
    int cr = -1, cl = 0, cans = 0;
    for (auto &it : q)
    {
        while (cl > it.l)
        {
            cl--;
            freq[v[cl]]++;
            if (freq[v[cl]] == 2 && v[cl])
                cans++;
        }
        while (cr < it.r)
        {
            cr++;
            freq[v[cr]]++;
            if (freq[v[cr]] == 2 && v[cr])
                cans++;
        }
        while (cl < it.l)
        {
            freq[v[cl]]--;
            if (freq[v[cl]] == 1 && v[cl])
                cans--;
            cl++;
        }
        while (cr > it.r)
        {
            freq[v[cr]]--;
            if (freq[v[cr]] == 1 && v[cr])
                cans--;
            cr--;
        }
        ans[it.idx] = cans * 2;
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
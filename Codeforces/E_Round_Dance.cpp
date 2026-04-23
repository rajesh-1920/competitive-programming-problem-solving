// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  17.10.2025

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
const int N = 2e5 + 10;
//------------------------------(solve)----------------------------------------------------
vector<int> vis(N / 32 + 5, 0);
#define on(x) (vis[x >> 5] & (1 << (x & 31)))
#define set(x) (vis[x >> 5] |= (1 << (x & 31)))

void dfs(int n, vector<int> g[], vector<int> &temp)
{
    stack<int> st;
    st.push(n);
    set(n);
    temp.push_back(n);
    while (!st.empty())
    {
        n = st.top();
        st.pop();
        for (auto it : g[n])
            if (!on(it))
            {
                temp.push_back(it);
                st.push(it);
                set(it);
            }
    }
}
void solve(void)
{
    int n;
    cin >> n;
    vector<int> g[n];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        g[x - 1].push_back(i);
        g[i].push_back(x - 1);
    }
    for (int i = 0; i < n; i++)
    {
        sort(all(g[i]));
        g[i].erase(unique(all(g[i])), g[i].end());
    }
    fill(all(vis), 0);
    int cnt = 0, mx = 0, ans = 0;
    vector<int> st;
    for (int i = 0; i < n; i++)
        if (!on(i))
        {
            mx++;
            vector<int> temp;
            dfs(i, g, temp);
            int c = 0;
            for (auto it : temp)
                c += g[it].size() == 1;
            if (c)
                st.push_back(c);
            else
                ans++;
        }
    sort(all(st));
    while (st.size() > 1)
    {
        int t1 = st.back();
        st.pop_back();
        int t2 = st.back();
        st.pop_back();
        t1--, t2--;
        t2 += t1;
        if (t2 == 0)
            ans++;
        else
            st.push_back(t2);
    }
    cout << ans + st.size() << ' ' << mx << '\n';
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
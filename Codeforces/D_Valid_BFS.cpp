// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  06.01.2025

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
void solve(void)
{
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1), child(n + 1);
    for (int i = 1, x, y; i < n; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<int> ar(n + 1), vis(n + 1, 0), pos(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> ar[i];
        pos[ar[i]] = i;
    }
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        int nd = q.front();
        q.pop();
        for (auto it : v[nd])
        {
            if (vis[it])
                continue;
            child[nd].push_back(it);
            vis[it] = 1;
            q.push(it);
        }
    }
    if (ar[1] != 1)
    {
        cout << "No\n";
        return;
    }
    q.push(1);
    int ii = 2;
    while (!q.empty())
    {
        int nd = q.front();
        q.pop();
        set<int> st;
        for (auto it : child[nd])
            st.insert(it);
        int cnt = child[nd].size();
        while (cnt--)
        {
            if (st.find(ar[ii]) == st.end())
            {
                cout << "No\n";
                return;
            }
            if (ii <= n)
                q.push(ar[ii++]);
        }
    }
    cout << "Yes\n";
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
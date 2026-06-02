// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  02.06.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const int N = 1e5 + 10;
const int LOG = 20;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int n, k;
    cin >> n >> k;
    vector<unordered_set<int>> v(n + 1);
    for (int i = 1, x, y; i < n; i++)
    {
        cin >> x >> y;
        v[x].insert(y), v[y].insert(x);
    }
    queue<int> tr;
    for (int i = 1; i <= n; i++)
        if (v[i].size() == 1)
            tr.push(i);
    int cnt = 0;
    vector<int> dis(n + 1, -1);
    while (!tr.empty())
    {
        int x = tr.front();
        tr.pop();
        queue<int> q, temp;
        q.push(x);
        temp.push(x);
        dis[x] = 0;
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            for (auto &it : v[t])
                if (dis[it] == -1 && dis[t] < k)
                {
                    dis[it] = dis[t] + 1, q.push(it), temp.push(it);
                    if (dis[it] == k)
                        cnt++;
                }
        }
        while (!temp.empty())
        {
            dis[temp.front()] = -1;
            temp.pop();
        }
        for (auto &it : v[x])
        {
            if (v[it].count(x))
                v[it].erase(x);
            if (v[it].size() == 1)
                tr.push(it);
        }
    }
    cout << cnt << '\n';
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
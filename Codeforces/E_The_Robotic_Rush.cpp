// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  06.06.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define Dbg(x) cout << #x << " = " << x << '\n'
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const int MOD = 1e8 + 7;
const int N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    set<int> rob, spik;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        rob.insert(i);
    }
    for (int i = 0, x; i < m; i++)
    {
        cin >> x;
        spik.insert(x);
    }
    string s;
    cin >> s;
    map<int, set<int>> mpl, mpr;
    for (int i = 0; i < n; i++)
    {
        auto it = spik.lower_bound(v[i]);
        if (it != spik.end())
            mpr[(*it) - v[i]].insert(i);
        if (it != spik.begin())
            mpl[v[i] - (*(--it))].insert(i);
    }
    int cnt = 0;
    for (auto &iit : s)
    {
        if (iit == 'R')
        {
            cnt++;
            auto it = mpr.upper_bound(cnt);
            queue<int> q;
            while (it != mpr.begin())
            {
                it--;
                q.push((*it).fi);
                for (auto &ii : (*it).sc)
                    if (rob.count(ii))
                        rob.erase(ii);
            }
            while (!q.empty())
            {
                mpr.erase(q.front());
                q.pop();
            }
        }
        else
        {
            cnt--;
            auto it = mpl.upper_bound(-cnt);
            queue<int> q;
            while (it != mpl.begin())
            {
                it--;
                q.push((*it).fi);
                for (auto &ii : (*it).sc)
                    if (rob.count(ii))
                        rob.erase(ii);
            }
            while (!q.empty())
            {
                mpl.erase(q.front());
                q.pop();
            }
        }
        cout << rob.size() << ' ';
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
        // cout << "Case " << T << ":\n";
        solve();
    }
    return 0;
}
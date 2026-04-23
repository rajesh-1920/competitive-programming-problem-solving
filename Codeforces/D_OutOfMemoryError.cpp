// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  18.01.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
#define int long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e8;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
void solve(void)
{
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> v(n), temp;
    for (auto &it : v)
        cin >> it;
    vector<pair<int, int>> vp(m);
    temp = v;
    queue<int> q;
    for (int i = 0; i < m; i++)
    {
        cin >> vp[i].fi >> vp[i].sc;
        vp[i].fi--;
        if (temp[vp[i].fi] + vp[i].sc > h)
            while (!q.empty())
            {
                temp[q.front()] = v[q.front()];
                q.pop();
            }
        else
            temp[vp[i].fi] += vp[i].sc, q.push(vp[i].fi);
    }
    for (auto &it : temp)
        cout << it << ' ';
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
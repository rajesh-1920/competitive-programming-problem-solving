// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  27.07.2025

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
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
void solve(void)
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n), cnt(x + 5, -1);
    for (auto &it : v)
        cin >> it;
    priority_queue<int> st[x + 5];
    for (int i = 0; i < n; i++)
    {
        int t = i - cnt[v[i]] - 1;
        cnt[v[i]] = i;
        st[v[i]].push(t);
    }
    int ans = n;
    for (int i = 1; i <= x; i++)
    {
        if (!st[i].empty())
        {
            int t = st[i].top();
            st[i].push(n - cnt[i] - 1);
            t = st[i].top();
            st[i].pop();
            st[i].push(t / 2);
            ans = min(ans, st[i].top());

            // {
            //     while (st[i].size())
            //     {
            //         cout << st[i].top() << ' ';
            //         st[i].pop();
            //     }
            //     cout << '\n';
            //     cout << '\n';
            // }
        }
    }
    cout << ans << '\n';
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
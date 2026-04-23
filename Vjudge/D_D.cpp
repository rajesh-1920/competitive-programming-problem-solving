// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  28.08.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, -1));
    multiset<int> st[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            st[i].insert(x);
        }
    }
    for (int i = 0; i < m; i++)
    {
        int p = 0, vl = inf;
        for (int j = 0; j < n; j++)
        {
            if (*(st[j].begin()) < vl)
            {
                p = j;
                vl = *(st[j].begin());
            }
        }
        v[p][i] = vl;
        st[p].erase(st[p].begin());
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == -1)
            {
                v[i][j] = *(st[i].begin());
                st[i].erase(st[i].begin());
            }
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
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
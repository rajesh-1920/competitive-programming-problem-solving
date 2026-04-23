// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  25.03.2025

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
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        v[x] = 0;
    }
    set<pair<int, int>> st; // size,indx
    vector<int> g[n + 1], sz(n + 5, 0);
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int t;
            cin >> t;
            if (v[i] != 0)
                g[t].push_back(i);
        }
        if (v[i] == 0)
            m = 0;
        st.insert({m, i});
        sz[i] = m;
    }

    vector<int> temp(n + 5, inf), vis(n + 5, 0);
    while (st.size())
    {
        int i = (*st.begin()).sc;
        v[i] = min(v[i], temp[i]);
        for (auto it : g[i])
        {
            st.erase({sz[it], it});
            sz[it]--;
            st.insert({sz[it], it});
            if (temp[it] == inf)
                temp[it] = v[i];
            else
                temp[it] += v[i];
        }
        v[i] = min(v[i], temp[i]);
        st.erase({sz[i], i});
    }

    for (int i = 1; i <= n; i++)
        cout << v[i] << ' ';
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
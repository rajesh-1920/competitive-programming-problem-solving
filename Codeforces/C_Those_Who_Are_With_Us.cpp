// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  16.06.2025

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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    vector<vector<int>> vv(n, vector<int>(m, 0));
    int ans;
    {
        int l = 0, r = 0, mx = 0;
        multiset<int> st;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> v[i][j];
                vv[i][j] = v[i][j];
                mx = max(mx, v[i][j]);
                st.insert(v[i][j]);
            }
        int xx = 0;
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < m; j++)
                if (v[i][j] == mx)
                    cnt++;
            if (cnt > xx)
                l = i, xx = cnt;
        }
        for (int i = 0; i < m; i++)
        {
            st.erase(st.find(v[l][i]));
            v[l][i] = v[l][i] - 1;
            st.insert(v[l][i]);
        }
        xx = 0;
        for (int i = 0; i < m; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
                if (v[j][i] == mx)
                    cnt++;
            if (cnt > xx)
                r = i, xx = cnt;
        }
        for (int i = 0; i < n; i++)
        {
            if (i != l)
            {
                st.erase(st.find(v[i][r]));
                st.insert(v[i][r] - 1);
            }
        }
        ans = *st.rbegin();
    }
    {
        int l = 0, r = 0, mx = 0;
        multiset<int> st;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                mx = max(mx, vv[i][j]);
                st.insert(vv[i][j]);
            }
        int xx = 0;
        for (int i = 0; i < m; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
                if (vv[j][i] == mx)
                    cnt++;
            if (cnt > xx)
                r = i, xx = cnt;
        }
        for (int i = 0; i < n; i++)
        {
            st.erase(st.find(vv[i][r]));
            vv[i][r] = vv[i][r] - 1;
            st.insert(vv[i][r]);
        }
        xx = 0;
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < m; j++)
                if (vv[i][j] == mx)
                    cnt++;
            if (cnt > xx)
                l = i, xx = cnt;
        }
        for (int i = 0; i < m; i++)
        {
            if (i != r)
            {
                st.erase(st.find(vv[l][i]));
                vv[l][i] = vv[l][i] - 1;
                st.insert(vv[l][i]);
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //         cout << vv[i][j] << ' ';
        //     cout << '\n';
        // }
        ans = min(ans, *st.rbegin());
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
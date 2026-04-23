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
const int N = 1e3 + 10;
//------------------------------(solve)----------------------------------------------------
vector<int> v[N], vis(N), temp;
void dfs(int n)
{
    vis[n] = 1;
    for (auto it : v[n])
    {
        if (vis[it] == 0)
            dfs(it);
    }
    temp.push_back(n + 1);
}
void solve(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        v[i].clear(), vis[i] = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
            if (s[j] != '0')
                v[i].push_back(j);
    }
    temp.clear();
    dfs(0);
    if (temp.size() != n)
        cout << "No\n";
    else
    {
        cout << "Yes\n";
        for (int i = 1; i < n; i++)
            cout << temp[i] << ' ' << temp[i - 1] << '\n';
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
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}
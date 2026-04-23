// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  15.02.2025

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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    vector<int> sum[n + 5];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum[v[i]].push_back(x);
    }
    for (auto &it : sum)
    {
        sort(rall(it));
        for (int j = 1; j < it.size(); j++)
            it[j] += it[j - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        int x = 0;
        for (int j = 1; j <= n; j++)
        {
            int t = sum[j].size() / i;
            if (t)
                x += sum[j][t * i - 1];
        }
        cout << x << ' ';
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
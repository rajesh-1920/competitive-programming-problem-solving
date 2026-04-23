// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  09.02.2025

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
const int N = 1e4 + 10;
//-----------------------------------------------------------------------------------------
vector<int> lp(N, inf);
void sieve()
{
    for (int i = 2; i < N; i++)
    {
        if (lp[i] == inf)
            for (int j = i; j < N; j += i)
                lp[j] = min(lp[j], i);
    }
}
void solve(void)
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    if (lp[n] != n)
    {
        int cnt = 1;
        for (int j = 0; j < m; j++)
            for (int i = 0; i < n; i++)
                arr[i][j] = cnt++;
    }
    else if (lp[m] != m)
    {
        int cnt = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                arr[i][j] = cnt++;
    }
    else
    {
        int cnt = 1;
        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j++)
                arr[i][j] = cnt++;
        //arr[n - 1][0] = cnt++;
        for (int i = 0; i < n; i++)
            arr[i][0] = cnt++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << ' ';
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
    sieve();
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}
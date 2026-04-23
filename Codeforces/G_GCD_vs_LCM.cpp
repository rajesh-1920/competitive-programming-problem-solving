// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  21.08.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
#define int unsigned long long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 100 + 10;
//------------------------------(solve)----------------------------------------------------
vector<int> pp;
void ss()
{
    pp.push_back(2);
    for (int i = 3; i < N; i += 2)
    {
        int fl = 1;
        for (int j = 2; j < i; j++)
            if (i % j == 0)
            {
                fl = 0;
                break;
            }
        if (fl)
            pp.push_back(i);
    }
    sort(all(pp));
}
void solve(void)
{
    int n, x;
    cin >> n >> x;
    int t = 1;
    for (int i = 0; i < n; i++)
    {
        t *= pp[i];
        if (t > x)
        {
            cout << -1 << '\n';
            return;
        }
    }
    for (int i = 0; i < n; i++)
        cout << t / pp[i] << ' ';
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
    ss();
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}
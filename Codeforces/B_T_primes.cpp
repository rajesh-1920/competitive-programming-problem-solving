// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  05.01.2026

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
const int N = 1e6 + 10;
//------------------------------(solve)----------------------------------------------------
vector<int> is(N, 1);
void sieve()
{
    is[1] = is[0] = 0;
    for (int i = 4; i < N; i += 2)
        is[i] = 0;
    for (int i = 3; i < N; i += 2)
        if (is[i])
            for (int j = i + i + i; j < N; j += 2 * i)
                is[j] = 0;
}
void solve(void)
{
    sieve();
    int n;
    cin >> n;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        int t = ((int)sqrt(x)) - 5;
        bool fl = false;
        for (int j = max(1LL, t);; j++)
        {
            if (j * j > x)
                break;
            if (j * j == x && is[j])
            {
                fl = true;
                break;
            }
        }
        cout << (fl == true ? "YES\n" : "NO\n");
    }
}
//-----------------------------------------------------------------------------------------
signed main()
{
    // cout << fixed << showpoint << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1, T;
    // cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}
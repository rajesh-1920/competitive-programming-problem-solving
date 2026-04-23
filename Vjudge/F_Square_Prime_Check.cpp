// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  27.08.2025

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
set<int> pp;
vector<int> lp(N, -1);
void sieve()
{
    pp.insert(2);
    for (int i = 3; i < N; i += 2)
    {
        if (lp[i] == -1)
        {
            pp.insert(i);
            for (int j = i; j < N; j += 2 * i)
                lp[j] = i;
        }
    }
}
void solve(void)
{
    int n;
    cin >> n;
    int s = sqrtl(n);
    for (int i = s - 10; i <= s + 10; i++)
    {
        if (i * i == n)
        {
            if (pp.find(i) != pp.end())
            {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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
// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  25.03.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
// #define int long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e7 + 10;
//-----------------------------------------------------------------------------------------
vector<int> cnt(N, 0);
vector<bool> is(N, false);

void sieve()
{
    for (int i = 3; i < N; i += 2)
    {
        if (is[i] == false)
        {
            for (int j = i * 3; j < N; j += (i * 2))
                is[j] = true;
        }
    }
    for (int i = 2; i < N; i++)
    {
        cnt[i] = cnt[i - 1];
        if (i & 1)
        {
            if (is[i] == false)
                cnt[i]++;
        }
        else if (i == 2)
            cnt[i] = 1;
    }
}
void solve(void)
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int t = (n / i);
        ans += cnt[t];
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
    sieve();
    cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}
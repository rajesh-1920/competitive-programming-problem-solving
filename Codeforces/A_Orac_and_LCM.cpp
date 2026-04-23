// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  08.02.2025

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
const int N = 2e5 + 10;
//-----------------------------------------------------------------------------------------
vector<int> lp(N, 1);
void sieve()
{
    for (int i = 2; i < N; i++)
    {
        if (lp[i] == 1)
            for (int j = i; j < N; j += i)
                if (lp[j] == 1)
                    lp[j] = i;
                else
                    lp[j] = min(i, lp[i]);
    }
}
int power(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
void solve(void)
{
    int n;
    cin >> n;
    map<int, multiset<int>> mp;
    int g = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        // dbg(x);
        while (x > 1)
        {
            int t = lp[x], cnt = 0;
            while (x % t == 0)
            {
                x /= t;
                cnt++;
            }
            // cout << t << ' ' << cnt << '\n';
            mp[t].insert(cnt);
        }
        // cout << '\n';
    }
    int ans = 1;
    for (int i = 1; i < N; i++)
    {
        if (lp[i] == i)
        {
            if (mp[i].size() == n)
            {
                mp[i].erase(mp[i].begin());
                int x = *mp[i].begin();
                ans *= power(i, x);
            }
            else if (mp[i].size() == n - 1)
            {
                int x = *mp[i].begin();
                ans *= power(i, x);
            }
        }
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
    // cin >> test;
    sieve();
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}
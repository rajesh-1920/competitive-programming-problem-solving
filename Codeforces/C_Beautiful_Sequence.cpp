// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  19.02.2025

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
const int MOD = 998244353;
const int N = 2e5 + 10;
//-----------------------------------------------------------------------------------------
inline int normal(int a, int m)
{
    a = a - (a / m) * m;
    if (a < 0)
        a += m;
    return a;
}
inline int modadd(int a, int b, int m)
{
    a = normal(a, m), b = normal(b, m);
    return normal(a + b, m);
}
inline int modsub(int a, int b, int m)
{
    a = normal(a, m), b = normal(b, m);
    return normal(a - b, m);
}
inline int modmul(int a, int b, int m)
{
    a = normal(a, m), b = normal(b, m);
    return normal(a * b, m);
}
inline int binexpo(int a, int b, int m)
{
    int ans = 1;
    a = normal(a, m);
    while (b)
    {
        if (b & 1)
            ans = modmul(ans, a, m);
        a = modmul(a, a, m);
        b >>= 1;
    }
    return normal(ans, m);
}
inline int moddiv(int a, int b, int m)
{
    return normal(modmul(a, binexpo(b, m - 2, m), m), m);
}
//-----------------------------------------------------------------------------------------
int fact[N];
void solve(void)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    int c1 = inf, c3 = -1;
    for (int i = 0; i < n; i++)
        if (v[i] == 1)
        {
            c1 = i;
            break;
        }
    for (int i = n - 1; i >= 0; i--)
        if (v[i] == 3)
        {
            c3 = i;
            break;
        }
    int c2 = 0, cnt = 0;
    for (int i = c1 + 1; i < c3; i++)
        if (v[i] == 2)
            c2++, cnt++;
        else
            cnt++;
    int ans = 0;
    if (cnt && c2)
    {
        ans = normal(c2, MOD);
        cnt--;
        for (int i = 1; i <= cnt; i++)
        // ans = modadd(ans, (moddiv(fact[cnt], modmul(fact[i], fact[cnt - i], MOD), MOD)), MOD);
        {
            ans = ans + (fact[cnt] / (fact[i] * fact[cnt - i]));
            dbg(cnt);
            dbg(ans);
        }
    }
    cout << ans << '\n';
}
void fac()
{
    fact[0] = 1;
    for (int i = 1; i < 10; i++)
        // fact[i] = normal(modmul(i, fact[i - 1], MOD), MOD);
        fact[i] = i * fact[i - 1];
}
//-----------------------------------------------------------------------------------------
signed main()
{
    // cout << fixed << showpoint << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1, T;
    cin >> test;
    fac();
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}
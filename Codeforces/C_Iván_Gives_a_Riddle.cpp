// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  07.05.2025

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
const int N = 1e5 + 10;
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
void solve(void)
{
    string s1, s2;
    cin >> s1 >> s2;
    string t1, t2;
    int n1 = s1.size(), n2 = s2.size();
    s1 = s1 + s2;
    sort(rall(s1));
    int fl = 0;
    while (!s1.empty())
    {
        if ((t1.size() <= t2.size() || fl) && t1.size() < n1)
            t1.push_back(s1.back()), s1.pop_back();
        else if (t2.size() < n2)
            t2.push_back(s1.back()), s1.pop_back();
        else
            fl = 1;
    }
    // dbg(t1);
    // dbg(t2);
    sort(rall(t1));
    sort(rall(t2));
    int res = 0, t = 1;
    while (!t1.empty())
    {
        res = modadd(res, modmul(t, (t1.back() - '0'), MOD), MOD);
        t = modmul(t, 10, MOD);
        t1.pop_back();
        // dbg(res);
    }
    t = 1;
    while (!t2.empty())
    {
        res = modadd(res, modmul(t, (t2.back() - '0'), MOD), MOD);
        t = modmul(t, 10, MOD);
        t2.pop_back();
    }
    // a %= MOD;
    // b %= MOD;
    // a = a + b;
    cout << res << '\n';
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
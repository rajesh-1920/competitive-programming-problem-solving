// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  16.06.2025

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
const int N = 1e6 + 10;
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
void ok()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = modmul(i, fact[i - 1], MOD);
}
void solve(void)
{
    int n;
    cin >> n;
    int cnt = 0, ans = 0, t = fact[n - 1];
    for (int i = n; i > 0; i--)
    {
        if (cnt > 1)
            t = moddiv(t, cnt, MOD);
        ans = modadd(ans, t, MOD);
        cnt++;
    }

    /*vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    // v.push_back(6);
    // v.push_back(7);
    cnt = 0;
    map<int, int> mp;
    do
    {
        int fl = 1;
        vector<int> b;
        int mx = 0;
        for (auto it : v)
        {
            mx = max(mx, it);
            b.push_back(mx);
        }
        for (int i = 1; i < v.size(); i++)
        {
            if (b[i] - b[i - 1] > 1)
                fl = 0;
        }
        if (fl)
        {
            mp[v[0]]++;
            cnt++;
        }
    } while (next_permutation(all(v)));
    cout << cnt << '\n';
    for (auto it : mp)
        cout << it.fi << ' ' << it.sc << '\n';*/
    cout << ans << '\n';
}
//-----------------------------------------------------------------------------------------
signed main()
{
    // cout << fixed << showpoint << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ok();
    int test = 1, T;
    cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}
// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  25.03.2025

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
    int n;
    string s, t = "";
    cin >> n >> s;
    for (auto it : s)
        if (it != '-')
            t.push_back(it);
    for (int i = 0; i + 1 < t.size(); i++)
    {
        if (t[i] > t[i + 1])
        {
            cout << 0 << '\n';
            return;
        }
    }
    s = '1' + s + '9';
    int las = 1, pos = 0;
    vector<int> v;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] != '-')
        {
            int now = s[i] - '0';
            int t = i - pos - 1;
            if (t == 1)
                v.push_back((now - las + 1));
            else if (t > 0)
            {
                now -= (las - 1);
                las = 1;
                int inc = t - 1, cnt = 1;
                // dbg(las);
                // dbg(now);
                // dbg(inc);
                int tt = 0;
                for (int i = las; i <= now; i++)
                {
                    tt += cnt;
                    cnt += inc;
                    // dbg(cnt);
                    inc++;
                }
                v.push_back(tt);
            }
            las = s[i] - '0';
            pos = i;
        }
    }
    int ans = 1;
    for (auto it : v)
        ans = modmul(ans, it, MOD);
    cout << ans << '\n';
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
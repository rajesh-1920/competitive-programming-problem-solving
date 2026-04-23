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
int ok(int i, int digit, string &s)
{
    if (i < 0)
        return 1;
    int ans = 0;
    if (s[i] != '-')
    {
        for (int t = s[i] - '0'; t > 0; t--)
            ans += ok(i - 1, t, s);
    }
    else
    {
        for (int t = digit; t > 0; t--)
            ans += ok(i - 1, t, s);
    }
    // dbg(ans);
    return ans;
}
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int n;
    string s, t = "";
    cin >> n >> s;
    s = '*' + s;
    vector<vector<int>> v(n + 5, vector<int>(15, 0));
    for (int i = 1; i <= 9; i++)
        v[0][i] = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == '-')
        {
            for (int j = 1; j <= 9; j++)
                v[i][j] += v[i - 1][j];
        }
        else
        {
            int t = s[i] - '0';
            v[i][t] = v[i - 1][t];
        }
        for (int j = 2; j <= 9; j++)
            v[i][j] = modadd(v[i][j - 1], v[i][j], MOD);
    }
    cout << v[n][9] << '\n';
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
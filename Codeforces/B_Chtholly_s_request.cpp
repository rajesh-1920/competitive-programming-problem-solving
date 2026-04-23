// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  10.03.2025

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
    int n, k;
    cin >> n >> k;
    set<int> st2, st;
    for (int i = 11; i <= 99; i += 11)
        st2.insert(i), st.insert(i);
    set<int> st4;
    for (auto it : st2)
        for (int i = 1; i <= 9; i++)
        {
            st4.insert(i * 1000 + it * 10 + i), st.insert(i * 1000 + it * 10 + i);
            st4.insert(i * 1000 + i), st.insert(i * 1000 + i);
        }
    set<int> st6;
    for (auto it : st4)
        for (int i = 1; i <= 9; i++)
        {
            st6.insert(i * 100000 + it * 10 + i), st.insert(i * 100000 + it * 10 + i);
            st6.insert(i * 100000 + i), st.insert(i * 100000 + i);
        }
    set<int> st8;
    for (auto it : st6)
        for (int i = 1; i <= 9; i++)
        {
            st8.insert(i * 10000000 + it * 10 + i), st.insert(i * 10000000 + it * 10 + i);
            st8.insert(i * 10000000 + i), st.insert(i * 10000000 + i);
        }
    set<int> st10;
    for (auto it : st8)
        for (int i = 1; i <= 9; i++)
        {
            st10.insert(i * 1000000000 + it * 10 + i), st.insert(i * 1000000000 + it * 10 + i);
            st10.insert(i * 1000000000 + i), st.insert(i * 1000000000 + i);
        }
    for (auto it : st8)
        for (int i = 1; i <= 9; i++)
            st.insert(i * 100000000000 + it * 10 + i), st.insert(i * 100000000000 + i);
    int ans = 0;
    for (auto it : st)
    {
        cout<<it<<' ';
        ans = modadd(ans, it, k);
        n--;
        if (n == 0)
            break;
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
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}
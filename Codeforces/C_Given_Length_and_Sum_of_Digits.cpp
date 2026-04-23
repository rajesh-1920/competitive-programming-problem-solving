// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  03.02.2025

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
void solve(void)
{
    int n, s;
    cin >> n >> s;
    if (s == 0)
    {
        if (n == 1)
            cout << 0 << ' ' << 0;
        else
            cout << -1 << ' ' << -1;
        return;
    }
    string st;
    for (int i = 0; i < n; i++)
        st.push_back('0');
    st[0] = '1';
    int temp = s;
    s -= 1;
    for (int i = n - 1; i > 0; i--)
    {
        if (s < 9)
        {
            st[i] = char('0' + s);
            s = 0;
            break;
        }
        st[i] = '9';
        s -= 9;
    }
    s++;
    if (s > 9)
    {
        cout << -1 << ' ' << -1;
        return;
    }
    st[0] = char('0' + s);
    cout << st << ' ';
    s = temp;
    for (int i = 0; i < n; i++)
        st[i] = '0';
    for (int i = 0; i < n; i++)
    {
        if (s < 9)
        {
            st[i] = char('0' + s);
            s = 0;
            break;
        }
        st[i] = '9';
        s -= 9;
    }
    cout << st;
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
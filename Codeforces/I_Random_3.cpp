// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  01.04.2025

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
    int a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << (a == 1 ? "No\n" : "Yes\n");
        return;
    }
    int c = a ^ b;
    a = max(a, b);
    string sa = "", s = "";
    while (a)
    {
        if (a & 1)
            sa.push_back('1');
        else
            sa.push_back('0');
        a /= 2;
    }
    string need = "";
    while (c)
    {
        if (c & 1)
            s.push_back('1');
        else
            s.push_back('0');
        need.push_back('0');
        c /= 2;
    }
    while (sa.size() > s.size())
        s.push_back('0'), need.push_back('0');
    while (sa.size() < s.size())
        sa.push_back('0');
    reverse(all(s));
    reverse(all(sa));
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            if (sa[i] == '0')
                need[i] = '1';
            else
                need[i] = '0';
            break;
        }
        if (sa[i] == '0')
            need[i] = '1';
        else
            need[i] = '0';
    }
    cout << sa << ' ' << s << '\n';
    cout << need;
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
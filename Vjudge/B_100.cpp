// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  15.08.2025

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
//------------------------------(solve)----------------------------------------------------
void solve(void)
{
    string s1, s2;
    cin >> s1 >> s2;
    string a1, a2;
    reverse(all(s1));
    reverse(all(s2));
    while (s1.size() < s2.size())
        s1.push_back('0');
    while (s1.size() > s2.size())
        s2.push_back('0');
    int c = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (c == 1)
        {
            if (s1[i] == '1' && s2[i] == '1')
                a1.push_back('1'), c = 1;
            else if (s1[i] == '1' || s2[i] == '1')
                a1.push_back('0'), c = 0;
            else
                a1.push_back('1'), c = 0;
        }
        else
        {
            if (s1[i] == '1' && s2[i] == '1')
                a1.push_back('0'), c = 1;
            else if (s1[i] == '1' || s2[i] == '1')
                a1.push_back('1');
            else
                a1.push_back('0');
        }
        if (s1[i] == '1' || s2[i] == '1')
            a2.push_back('1');
        else
            a2.push_back('0');
    }
    if (c)
        a1.push_back('1'), a2.push_back('0');

    string ans;
    for (int i = 0; i < a1.size(); i++)
    {
        if (a2[i] == '0')
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
        if (a1[i] == '1')
            ans.push_back('1');
        else
            ans.push_back('0');
    }
    // reverse(all(ans));
    int t = 0, x = 0;
    //cout << ans << '\n';
    for (auto it : ans)
    {
        if (it == '1')
            x += t;
        if (t == 0)
            t++;
        else
            t *= 2;
    }
    cout << x << '\n';
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
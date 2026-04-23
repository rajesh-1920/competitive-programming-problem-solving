// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  01.02.2025

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
    string s;
    cin >> s;
    vector<pair<int, int>> ans;
    for (int i = 0; i < 12; i++)
    {
        if (s[i] == 'X')
        {
            ans.push_back({1, 12});
            break;
        }
    }
    for (int i = 0; i < 6; i++)
    {
        if (s[i] == 'X' && s[i + 6] == 'X')
        {
            ans.push_back({2, 6});
            break;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (s[i] == 'X' && s[i + 4] == 'X' && s[i + 8] == 'X')
        {
            ans.push_back({3, 4});
            break;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (s[i] == 'X' && s[i + 3] == 'X' && s[i + 6] == 'X' && s[i + 9] == 'X')
        {
            ans.push_back({4, 3});
            break;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        if (s[i] == 'X' && s[i + 2] == 'X' && s[i + 4] == 'X' && s[i + 6] == 'X' && s[i + 8] == 'X' && s[i + 10] == 'X')
        {
            ans.push_back({6, 2});
            break;
        }
    }
    sort(all(s));
    if (s[0] == 'X' && s[11] == 'X')
        ans.push_back({12, 1});
    cout << ans.size() << ' ';
    for (auto it : ans)
        cout << it.fi << 'x' << it.sc << ' ';
    cout << '\n';
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
// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  26.05.2025

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
    int n, m;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    cin >> m;
    while (m--)
    {
        string s;
        cin >> s;
        int fl = 1;
        if (s.size() != n)
            fl = 0;
        map<char, int> mp;
        map<int, char> ch;
        for (int i = 0; i < n; i++)
        {
            if (fl == 0)
                break;
            if (mp.find(s[i]) != mp.end())
                if (mp[s[i]] != v[i])
                    fl = 0;
            if (ch.find(v[i]) != ch.end())
                if (ch[v[i]] != s[i])
                    fl = 0;
            mp[s[i]] = v[i];
            ch[v[i]] = s[i];
        }
        if (fl)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
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
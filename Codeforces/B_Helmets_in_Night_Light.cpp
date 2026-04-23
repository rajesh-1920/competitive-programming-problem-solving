// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  28.08.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
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
string longestPalindrome(string s)
{
    string t = "#";
    for (char c : s)
        t += c, t += "#";
    int n = t.size();
    vector<int> P(n, 0);
    int C = 0, R = 0, maxLen = 0, centerIndex = 0;
    for (int i = 0; i < n; i++)
    {
        int mirr = 2 * C - i;
        if (i < R)
            P[i] = min(R - i, P[mirr]);
        int a = i + P[i] + 1, b = i - P[i] - 1;
        while (a < n && b >= 0 && t[a] == t[b])
        {
            P[i]++;
            a++;
            b--;
        }
        if (i + P[i] > R)
        {
            C = i;
            R = i + P[i];
        }
        if (P[i] > maxLen)
        {
            maxLen = P[i];
            centerIndex = i;
        }
    }
    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}

void solve(void)
{
    // int n, p;
    // cin >> n >> p;
    // vector<pair<int, int>> v(n);
    // for (auto &it : v)
    //     cin >> it.sc;
    // for (auto &it : v)
    //     cin >> it.fi;
    // multiset<pair<int, int>> st;
    // for (auto it : v)
    //     st.insert({it.fi, it.sc});
    // map<int, int> mp;
    // mp[(*st.begin()).fi] = (*st.begin()).sc;
    // st.erase(st.begin());
    // int ans = p;
    // while (st.size())
    // {
    //     int t = (*mp.begin()).fi;
    //     if (t >= p)
    //         ans += p;
    //     else
    //     {
    //         ans += t;
    //         mp[t]--;
    //         if (mp[t] == 0)
    //             mp.erase(t);
    //     }
    //     mp[(*st.begin()).fi] += (*st.begin()).sc;
    //     st.erase(st.begin());
    // }
    // cout << ans << '\n';
    string s;
    cin >> s;
    cout << longestPalindrome(s);
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
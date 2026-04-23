// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  04.03.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
// #define int long long int
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
    int l = 1, r = 1;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '0')
        {
            int cnt = 0;
            for (int j = i + 1; j < s.size(); j++)
                if (s[j] == '0')
                    cnt++;
                else
                    break;
            l = i - cnt;
            l = max(l, 1);
            r = l + s.size() - i - 1;
            break;
        }
    cout << 1 << ' ' << s.size() << ' ' << l << ' ' << r << '\n';

    // int mx = 0, pos0 = -1;
    // for (int i = 0; i < s.size(); i++)
    // {
    //     if (s[i] == '1')
    //         mx++;
    //     else
    //         pos0 = i + 1;
    // }
    // if (mx == s.size() || mx == 0)
    // {
    //     cout << 1 << ' ' << s.size() << ' ' << 1 << ' ' << 1 << '\n';
    //     return;
    // }
    // if (s[s.size() - 1] == '0')
    //     mx++;
    // int l = 1, fl = 0, pos = -1, pos1 = -1;
    // for (int i = 0; i < s.size(); i++)
    // {
    //     if (s[i] == '1')
    //         fl = 1;
    //     else if (fl)
    //     {
    //         l = s.size() - i;
    //         pos = i;
    //         break;
    //     }
    // }
    // if (pos == -1)
    // {
    //     cout << 1 << ' ' << s.size() << ' ' << pos0 << ' ' << pos0 << '\n';
    //     return;
    // }

    // int cc = 0;
    // for (int i = 0; i < pos; i++)
    //     if (s[i] == '1')
    //         cc++;
    // mx = 0;
    // vector<int> v[5020], res;
    // int t = 0;
    // set<int> st, vbv[5020];
    // for (int i = 0; i < pos; i++)
    // {
    //     if (s[i] == '1')
    //     {
    //         int oo = pos;
    //         for (int j = i; j < i + l; j++)
    //         {
    //             if (s[j] == '0' && s[oo] == '1')
    //             {
    //                 v[t].push_back(oo);
    //                 vbv[t].insert(oo);
    //             }
    //             if (s[j] == '1' && s[oo] == '0')
    //             {
    //                 v[t].push_back(oo);
    //                 vbv[t].insert(oo);
    //             }
    //             oo++;
    //         }
    //         res.push_back(i + 1);
    //         st.insert(t);
    //         t++;
    //     }
    // }
    // vector<pair<int, int>> g[5020];
    // for (int i = 0; i < t; i++)
    // {
    //     for (int j = 1; j < v[i].size(); j++)
    //         g[v[i][j - 1]].push_back({v[i][j], i});
    // }
    // int i = pos;
    // while (true)
    // {
    //     int mn = inf;
    //     if (st.size() == 1 || i == inf)
    //         break;
    //     for (auto it : g[i])
    //     {
    //         if (st.find(it.sc) != st.end())
    //             mn = min(mn, it.fi);
    //     }
    //     set<int> temp;
    //     for (auto it : st)
    //         if (vbv[it].find(mn) == vbv[it].end())
    //             temp.insert(it);
    //     for (auto it : temp)
    //         st.erase(it);
    //     if (st.size() == 1)
    //         break;
    //     i = mn;
    // }
    // pos1 = res[*st.begin()];
    // cout << 1 << ' ' << s.size() << ' ' << pos1 << ' ' << pos1 + l - 1 << '\n';
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
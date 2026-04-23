// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  16.06.2025

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
vector<int> v;
map<pair<int, int>, int> mp;
int ok(string &s1, string &s2, int &n2, int n, int i)
{
    if (i == v.size())
        return inf;
    if (mp.find({n, i}) != mp.end())
        return mp[{n, i}];
    string sn = to_string(n);
    int cnt = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[s1.size() - i - 1] == sn[s1.size() - i - 1])
            cnt++;
        if (s2[s1.size() - i - 1] == sn[s1.size() - i - 1])
            cnt++;
    }
    cnt = min(cnt, ok(s1, s2, n2, n, i + 1));
    if (n + v[i] <= n2)
        cnt = min(cnt, ok(s1, s2, n2, n + v[i], i + 1));
    return mp[{n, i}] = cnt;
}
void solve(void)
{
    int n1, n2;
    cin >> n1 >> n2;
    string s1, s2, t;
    s1 = to_string(n1);
    s2 = to_string(n2);
    // cout << ok(s1, s2, n2, n1, 0) << '\n';
    t = s1;
    int fl = 0, fg = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (fl)
            t[i] = '*';
        else
        {
            int t1 = s1[i] - '0', t2 = s2[i] - '0';
            if (t1 + 1 == t2)
            {
                int c1 = 0, c2 = 0;
                for (int j = i + 1; j < s1.size(); j++)
                    if (s1[j] == '9')
                        c1++;
                    else
                        break;
                for (int j = i + 1; j < s1.size(); j++)
                    if (s2[j] == '0')
                        c2++;
                    else
                        break;
                if (c1 <= c2)
                {
                    for (int j = i + 1; j < s1.size(); j++)
                        if (s1[j] == '9')
                            t[j] = '9', i = j;
                        else
                            break;
                }
                else
                {
                    t[i] = s2[i];
                    for (int j = i + 1; j < s1.size(); j++)
                        if (s2[j] == '0')
                            t[j] = '0', i = j;
                        else
                            break;
                }
                fl = 1;
            }
            else if (t1 + 1 < t2)
            {
                t[i] = '*';
                fl = 1;
            }
        }
    }
    // dbg(t);
    int ans = 0;
    for (int i = 0; i < t.size(); i++)
        if (t[i] == s1[i])
            ans++;
    for (int i = 0; i < t.size(); i++)
        if (t[i] == s2[i])
            ans++;
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
    int xx = 1;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            v.push_back(xx);
        xx *= 10;
    }
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}
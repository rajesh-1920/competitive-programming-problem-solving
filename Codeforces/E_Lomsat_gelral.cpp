// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  02.06.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define Dbg(x) cout << #x << " = " << x << '\n'
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
int sz = 1;
//-----------------------------------------------------------------------------------------
bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.fi / sz != b.fi / sz)
        return a.fi / sz < b.fi / sz;
    if ((a.fi / sz) & 1)
        return a.sc > b.sc;
    return a.sc < b.sc;
}
void dfs(int n, int &cnt, vector<int> &in, vector<int> &siz, vector<int> &temp, vector<vector<int>> &g)
{
    in[n] = cnt++;
    temp.push_back(n);
    for (auto &it : g[n])
    {
        if (in[it] == -1)
        {
            siz[n]++;
            dfs(it, cnt, in, siz, temp, g);
            siz[n] += siz[it];
        }
    }
}
void solve(void)
{
    int n, crr = -1, cll = 0;
    cin >> n;
    sz = max(sz, (int)sqrt(n));
    vector<int> v(n), in(n, -1), siz(n, 0), freq(n + 1, 0), temp;
    for (auto &it : v)
        cin >> it;
    vector<vector<int>> g(n);
    for (int i = 1, x, y; i < n; i++)
    {
        cin >> x >> y;
        g[x - 1].push_back(y - 1), g[y - 1].push_back(x - 1);
    }
    vector<long long int> ans(n);
    vector<pair<int, int>> query;
    n = 0;
    dfs(0, n, in, siz, temp, g);
    for (int i = 0; i < v.size(); i++)
        query.push_back({in[i], in[i] + siz[i]});
    sort(all(query), cmp);
    map<int, long long int> mp;
    for (auto &it : query)
    {
        while (cll > it.fi)
        {
            cll--;
            if (mp.count(freq[v[temp[cll]]]))
            {
                mp[freq[v[temp[cll]]]] -= v[temp[cll]];
                if (mp[freq[v[temp[cll]]]] == 0)
                    mp.erase(freq[v[temp[cll]]]);
            }
            freq[v[temp[cll]]]++;
            mp[freq[v[temp[cll]]]] += v[temp[cll]];
        }
        while (crr < it.sc)
        {
            crr++;
            if (mp.count(freq[v[temp[crr]]]))
            {
                mp[freq[v[temp[crr]]]] -= v[temp[crr]];
                if (mp[freq[v[temp[crr]]]] == 0)
                    mp.erase(freq[v[temp[crr]]]);
            }
            freq[v[temp[crr]]]++;
            mp[freq[v[temp[crr]]]] += v[temp[crr]];
        }
        while (cll < it.fi)
        {
            if (mp.count(freq[v[temp[cll]]]))
            {
                mp[freq[v[temp[cll]]]] -= v[temp[cll]];
                if (mp[freq[v[temp[cll]]]] == 0)
                    mp.erase(freq[v[temp[cll]]]);
            }
            freq[v[temp[cll]]]--;
            if (freq[v[temp[cll]]])
                mp[freq[v[temp[cll]]]] += v[temp[cll]];
            cll++;
        }
        while (crr > it.sc)
        {
            if (mp.count(freq[v[temp[crr]]]))
            {
                mp[freq[v[temp[crr]]]] -= v[temp[crr]];
                if (mp[freq[v[temp[crr]]]] == 0)
                    mp.erase(freq[v[temp[crr]]]);
            }
            freq[v[temp[crr]]]--;
            if (freq[v[temp[crr]]])
                mp[freq[v[temp[crr]]]] += v[temp[crr]];
            crr--;
        }
        ans[temp[it.fi]] = (*--mp.end()).sc;
    }
    for (auto &it : ans)
        cout << it << ' ';
    cout << '\n';
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
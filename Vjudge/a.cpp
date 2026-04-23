// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  25.03.2025

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
const int N = 1e6 + 10;
//-----------------------------------------------------------------------------------------

struct node
{
    int nxt[26];
    map<int,int>mp;
    node()
    {
        memset(nxt, -1, sizeof(nxt));
    }
};
vector<node> trie(1);
inline void add(string &s)
{
    int root = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (trie[root].nxt[s[i] - 'a'] == -1)
        {
            trie[root].nxt[s[i] - 'a'] = trie.size();
            trie.emplace_back();
        }
        root = trie[root].nxt[s[i] - 'a'];
        trie[root].mp[s.length() - i - 1]++;
    }
}

inline int qry(string &s)
{
    int root = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '#')
            return trie[root].mp[s.length() - i];
        if (trie[root].nxt[s[i] - 'a'] == -1)
            return 0;
        root = trie[root].nxt[s[i] - 'a'];
    }
    return trie[root].mp[0];
}

void solve(void)
{
    int n, m;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        reverse(all(s));
        mp[s.size()]++;
        add(s);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        reverse(all(s));
        if (s[0] == '#')
            cout << mp[s.size()] << '\n';
        else
            cout << qry(s) << '\n';
    }
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
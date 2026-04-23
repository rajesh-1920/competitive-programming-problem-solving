// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  04.03.2025

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
    map<char, int> mp;
    string s, t;
    cin >> t >> s;
    for (int i = 0; i < t.size(); i++)
    {
        mp[t[i]]--;
        mp[s[i]]++;
    }
    multiset<char> st;
    for (auto it : mp)
        if (it.sc != 0)
            st.insert(it.fi);
    if (st.empty())
    {
        cout << "YES\n";
        return;
    }

    for (int i = t.size(); i < s.size(); i++)
    {
        if (mp[s[i]] == 0)
            st.insert(s[i]);
        mp[s[i]]++;
        if (mp[s[i]] == 0)
            st.erase(st.find(s[i]));
            
        if (mp[s[i - t.size()]] == 0)
            st.insert(s[i - t.size()]);
        mp[s[i - t.size()]]--;
        if (mp[s[i - t.size()]] == 0)
            st.erase(st.find(s[i - t.size()]));

        if (st.empty())
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
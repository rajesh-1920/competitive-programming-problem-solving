// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  06.06.2025

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
// const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int n, m;
    cin >> n >> m;
    set<int> st;
    map<int, int> mp;
    for (int i = 0; i <= n; i++)
        st.insert(i);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (st.find(x) != st.end())
            st.erase(x);
        else if (x <= n)
            mp[x]++;
    }
    set<int> ss;
    for (auto it : st)
    {
        int fl = 1, x;
        for (auto itt : mp)
        {
            if (itt.fi > it)
                break;
            if ((it - itt.fi) % m == 0)
            {
                fl = 0;
                x = itt.fi;
                break;
            }
        }
        if (fl)
        {
            cout << it << '\n';
            return;
        }
        else
        {
            ss.insert(it);
            mp[x]--;
            if (mp[x] == 0)
                mp.erase(x);
        }
    }
    for (auto it : ss)
        st.erase(it);
    cout << (*st.begin()) << '\n';
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
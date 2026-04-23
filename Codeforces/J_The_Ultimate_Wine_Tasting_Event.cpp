// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  28.02.2025

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
    int n;
    string s;
    cin >> n >> s;
    set<int> w, r, st;
    // for (int i = 0; i < 2 * n; i++)
    // {
    //     st.insert(i);
    //     if (s[i] == 'W')
    //         w.insert(i);
    //     else
    //         r.insert(i);
    // }
    // vector<int> a1, a2;
    // while (!st.empty())
    // {
    //     int it = *st.begin();
    //     a1.push_back(it);
    //     if (w.size() == 0)
    //     {
    //         int t = *r.begin();
    //         r.erase(t);
    //         st.erase(t);
    //         a2.push_back(t);
    //         continue;
    //     }
    //     int t = *w.begin();
    // }
    // for (int i = 0; i < n; i++)
    //     swap(s[a1[i]], s[a2[i]]);
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<s[i];
    //     if (s[i] != 'W')
    //     {
    //         cout << "NO\n";
    //         return;
    //     }
    // }
    cout << "YES\n";
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
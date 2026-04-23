// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  22.03.2025

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
    map<int, int> st;
    int t = 1;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
    {
        cin >> it;
        st[it]++;
        if (st[it] > 1)
            t = 0;
    }
    if (st.size() == 1)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int fl = 1;
    for (auto it : v)
    {
        if (t && fl)
        {
            cout << 'R';
            fl = 0;
        }
        else if (st[it] > 1 && fl)
        {
            cout << 'R';
            fl = 0;
        }
        else
            cout << 'B';
    }
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
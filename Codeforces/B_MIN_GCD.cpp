// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  01.04.2025

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
    cin >> n;
    map<int, int> mp;
    vector<int> v(n);
    for (auto &it : v)
    {
        cin >> it;
        mp[it]++;
    }
    int mn = (*mp.begin()).fi;
    if (mp[mn] > 1)
    {
        cout << "Yes\n";
        return;
    }
    mp.clear();
    vector<int> st;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == mn)
            continue;
        if (v[i] % mn == 0 && mp[v[i]] == 0)
        {
            st.push_back(v[i]);
            mp[v[i]]++;
        }
    }
    n = st.size();
    if (n == 0)
    {
        cout << "No\n";
        return;
    }
    int gc = st.back();
    // dbg(gc);
    for (int i = 0; i < n; i++)
    {
        gc = gcd(st[i], gc);
        if (gc == mn)
        {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
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
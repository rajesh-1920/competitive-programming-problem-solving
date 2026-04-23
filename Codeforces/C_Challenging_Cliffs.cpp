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
const int N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int n, t = -1;
    cin >> n;
    map<int, int> mp;
    vector<int> v(n);
    for (auto &it : v)
    {
        cin >> it;
        mp[it]++;
        if (mp[it] > 1)
            t = it;
    }
    sort(all(v));
    if (n == 2)
        cout << v[0] << ' ' << v[1] << '\n';
    else if (t != -1)
    {
        int fl = 0;
        for (int i = 0; i < n; i++)
        {
            if (fl)
                cout << v[i] << ' ';
            if (v[i] == t)
                fl = 1;
        }
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << ' ';
            if (v[i] == t)
                break;
        }
        cout << '\n';
    }
    else
    {
        int mn = inf, p = 0;
        for (int i = 0; i + 1 < n; i++)
        {
            if (v[i + 1] - v[i] < mn)
            {
                mn = v[i + 1] - v[i];
                p = i;
                // dbg(p);
            }
        }
        // dbg(p);
        int fl = 0;
        for (int i = 0; i < n; i++)
        {
            if (fl)
                cout << v[i] << ' ';
            if (i == p)
                fl = 1;
        }
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << ' ';
            if (i == p)
                break;
        }
        cout << '\n';
    }
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
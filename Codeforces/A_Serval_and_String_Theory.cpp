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
    int n, k;
    string s;
    cin >> n >> k >> s;
    map<char, int> mp;
    for (auto it : s)
        mp[it]++;
    if (mp.size() == 1)
    {
        cout << "NO\n";
        return;
    }
    if (k == 0)
    {
        int t = s.size() - 1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] > s[t])
            {
                // dbg(i);
                cout << "NO\n";
                return;
            }
            if (s[i] < s[t])
            {
                cout << "YES\n";
                return;
            }
            t--;
        }
        cout << "NO\n";
    }
    else
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
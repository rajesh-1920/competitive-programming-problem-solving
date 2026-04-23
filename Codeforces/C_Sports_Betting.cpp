// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  31.07.2025

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
//------------------------------(solve)----------------------------------------------------
void solve(void)
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    sort(all(v));
    map<int, int> mp;
    int c2 = 0;
    for (auto it : v)
    {
        if (mp.empty())
            mp[it]++;
        else
        {
            if (it - (*(--mp.end())).fi > 1)
            {
                for (auto it : mp)
                    if (it.sc > 1)
                        c2++;
                mp.clear();
            }
            mp[it]++;
        }
        if (c2 >= 2)
            mp[it] = 4;
        else
            c2 = 0;
        if (mp[it] >= 4)
        {
            cout << "Yes\n";
            return;
        }
    }
    for (auto it : mp)
        if (it.sc > 1)
            c2++;
    if (c2 >= 2)
        cout << "Yes\n";
    else
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
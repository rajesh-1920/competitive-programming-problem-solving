// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  21.08.2025

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
    map<int, int> mp;
    for (int i = 0, x; i < n; i++)
        cin >> x, mp[x % 10]++;
    for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
            {
                if ((i + j + k) % 10 == 3)
                {
                    if (i == j && i == k)
                    {
                        if (mp[i] > 2)
                        {
                            cout << "YES\n";
                            return;
                        }
                    }
                    else if (i == j)
                    {
                        if (mp[i] > 1 && mp[k])
                        {
                            cout << "YES\n";
                            return;
                        }
                    }
                    else if (j == k)
                    {
                        if (mp[i] && mp[j] > 1)
                        {
                            cout << "YES\n";
                            return;
                        }
                    }
                    else if (i == k)
                    {
                        if (mp[i] > 1 && mp[j])
                        {
                            cout << "YES\n";
                            return;
                        }
                    }
                    else
                    {
                        if (mp[i] && mp[j] && mp[k])
                        {
                            cout << "YES\n";
                            return;
                        }
                    }
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
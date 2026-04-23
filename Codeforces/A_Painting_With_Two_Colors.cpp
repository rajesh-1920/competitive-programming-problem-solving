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
    int n, a, b;
    cin >> n >> a >> b;
    // vector<int> v(n); for (auto &it : v) cin >> it;
    // vector<vector<int>> v(110, vector<int>(110, 0));
    if (n % 2 == b % 2 && n % 2 == a % 2)
        cout << "YES\n";
    else if (n % 2==0)
    {
        if (b % 2 == 1)
            cout << "NO\n";
        else if (a % 2 == 1)
        {
            if (b < a)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
        else
            cout << "YES\n";
    }
    else
    {
        if (b % 2 == 0)
            cout << "NO\n";
        else if (a % 2 == 0)
        {
            if (b < a)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
        else
            cout << "YES\n";
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
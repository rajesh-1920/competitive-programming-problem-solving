// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  08.03.2025

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
    int sum = 0;
    for (auto it : s)
        sum += it - '0';
    if (sum == 0)
    {
        cout << "YES\n";
        return;
    }
    for (int i = 1; i <= sum + 5; i++)
    {
        if (sum % i == 0)
        {
            int cnt = 0, sm = 0, fl = 1;
            for (auto ii : s)
            {
                int t = ii - '0';
                if (sm + t > i)
                {
                    fl = 0;
                    break;
                }
                else
                    sm += t;
                if (sm == i)
                {
                    cnt++;
                    sm = 0;
                }
            }
            if (fl && sm == 0 && cnt > 1)
            {
                cout << "YES\n";
                return;
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
    // cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}
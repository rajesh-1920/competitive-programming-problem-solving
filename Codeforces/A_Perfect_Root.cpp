// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  18.01.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
#define int long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e8;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
//-----------------------------------------------------------------------------------------
signed main()
{
    // cout << fixed << showpoint << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1, T, cnt = 1;
    cin >> test;
    for (T = 1; T <= test; T++)
    {
        int n;
        cin >> n;
        while (n--)
        {
            cout << cnt << ' ';
            cnt++;
        }

        cout << '\n';
    }
    return 0;
}
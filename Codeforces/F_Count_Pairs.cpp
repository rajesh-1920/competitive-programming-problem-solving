// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  17.01.2026

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
const int N = 1e3 + 10;
//------------------------------(solve)----------------------------------------------------
void solve(void)
{
    vector<int> v(N, 0);
    for (int i = 0; i < N; i++)
    {
        int cnt = 0;
        int t = sqrt(i);
        for (int x = -t; x * x <= i || x < 0; x++)
            for (int y = -t; y * y <= i; y++)
                if (x * x + y * y <= i)
                    cnt++;
        v[i] = cnt;
    }
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        if (x < 0)
            cout << "0\n";
        else
            cout << v[x] << '\n';
    }
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
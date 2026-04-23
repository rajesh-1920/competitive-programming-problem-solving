// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  08.05.2025

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
    int n, x, y;
    cin >> n >> x >> y;
    x--, y--;
    vector<int> v(n, -1);
    v[x] = 0, v[y] = 1;
    for (int i = x - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            if (v[n - 1] == -1)
                v[i] = v[i + 1] ^ 1;
            else
            {
                if (v[n - 1] == 0)
                    if (v[i + 1] == 0)
                        v[i] = 1;
                    else
                        v[i] = 2;
                else if (v[i + 1] == 1)
                    v[i] = 0;
                else
                    v[i] = 2;
            }
        }
        else
        {
            if (v[i - 1] == -1)
                v[i] = v[i + 1] ^ 1;
            else
            {
                if (v[i - 1] == 0)
                    if (v[i + 1] == 0)
                        v[i] = 1;
                    else
                        v[i] = 2;
                else if (v[i + 1] == 1)
                    v[i] = 0;
                else
                    v[i] = 2;
            }
        }
    }

    for (int i = y - 1; i > x; i--)
    {
        if (v[i - 1] == -1)
            v[i] = v[i + 1] ^ 1;
        else
        {
            if (v[i - 1] == 0)
                if (v[i + 1] == 0)
                    v[i] = 1;
                else
                    v[i] = 2;
            else if (v[i + 1] == 1)
                v[i] = 0;
            else
                v[i] = 2;
        }
    }

    for (int i = y + 1; i < n; i++)
    {
        if (i == n - 1)
        {
            if (v[0] == -1)
                v[i] = v[i - 1] ^ 1;
            else
            {
                if (v[0] == 0)
                    if (v[i - 1] == 0)
                        v[i] = 1;
                    else
                        v[i] = 2;
                else if (v[i - 1] == 1)
                    v[i] = 0;
                else
                    v[i] = 2;
            }
        }
        else
        {
            if (v[i + 1] == -1)
                v[i] = v[i - 1] ^ 1;
            else
            {
                if (v[i - 1] == 0)
                    if (v[i + 1] == 0)
                        v[i] = 1;
                    else
                        v[i] = 2;
                else if (v[i + 1] == 1)
                    v[i] = 0;
                else
                    v[i] = 2;
            }
        }
    }

    for (auto it : v)
        cout << it << ' ';
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
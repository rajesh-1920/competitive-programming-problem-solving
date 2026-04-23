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
    int r;
    cin >> r;
    // vector<int> v(n); for (auto &it : v) cin >> it;
    // vector<vector<int>> v(110, vector<int>(110, 0));
    r *= 2;
    for (int ii = 1; ii <= 30; ii++)
    {
        set<vector<int>> st;
        for (int i = 3; i < ii * 2; i++)
        {
            int c = sqrt(ii * 4 * ii - i * i);
            for (int j = 1; j <= c; j++)
            {
                int tt = sqrt(i * i + j * j);
                if (tt * tt == i * i + j * j)
                {
                    // cout << i << ' ' << j << ' ' << tt << '\n';
                    vector<int> v = {i, j, tt};
                    sort(all(v));
                    st.insert(v);
                }
            }
        }
        // dbg(ii);
        cout << ii << ' ' << st.size() << '\n';
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
// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  11.07.2025

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
    int a, b, c;
    cin >> a >> b >> c;
    int x = b * b - (4 * a * c);

    if (x < 0)
        cout << 0 << '\n';
    else if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                cout << -1 << '\n';
            else
                cout << 0 << '\n';
        }
        else
        {
            cout << 1 << '\n';
            double cc = -c, bb = b;
            cout << cc / bb << '\n';
        }
    }
    else
    {
        double bb = -b, aa = 2 * a, xx = x;
        xx = sqrt(xx);
        set<double> st;
        st.insert((bb - xx) / aa);
        st.insert((bb + xx) / aa);
        cout << st.size() << '\n';
        for (auto it : st)
            cout << it << '\n';
    }
}
//-----------------------------------------------------------------------------------------
signed main()
{
    cout << fixed << showpoint << setprecision(10);
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
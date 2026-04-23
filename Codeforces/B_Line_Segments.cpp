// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  06.07.2025

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
    int n, a, b, x, y, s = 0;
    cin >> n >> a >> b >> x >> y;
    vector<int> v(n);
    for (auto &it : v)
    {
        cin >> it;
        s += it;
    }
    if (a == x && b == y)
    {
        if (n == 1)
            cout << "No\n";
        else if (n == 2)
        {
            if (v[0] == v[1])
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        else
        {
            sort(all(v));
            s -= v.back();
            if (s >= v.back())
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    else
    {
        if (s * s >= ((a - x) * (a - x) + (b - y) * (b - y)))
        {
            int dis = (sqrtl((a - x) * (a - x) + (b - y) * (b - y)));
            dis -= 10;
            dis = max(0LL, dis);
            while (true)
            {
                if (dis * dis > (a - x) * (a - x) + (b - y) * (b - y))
                    break;
                dis++;
            }
            dis--;
            sort(all(v));
            if (dis >= v.back())
                cout << "Yes\n";
            else
            {
                dis = v.back() - dis;
                if (dis <= (s - (v.back())))
                    cout << "Yes\n";
                else
                    cout << "No\n";
            }
        }
        else
            cout << "No\n";
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
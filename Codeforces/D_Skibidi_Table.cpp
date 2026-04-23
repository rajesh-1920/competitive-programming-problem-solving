// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  08.04.2025

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
int find_value(int x, int y, int size)
{
    if (size == 2)
    {
        if (x == 1 && y == 1)
            return 1;
        if (x == 2 && y == 2)
            return 2;
        if (x == 2 && y == 1)
            return 3;
        if (x == 1 && y == 2)
            return 4;
    }
    int md = size / 2;
    if (x <= md && y <= md)
        return find_value(x, y, md);
    else if (x > md && y > md)
        return 1LL * md * md + find_value(x - md, y - md, md);
    else if (x > md && y <= md)
        return 2LL * md * md + find_value(x - md, y, md);
    else
        return 3LL * md * md + find_value(x, y - md, md);
}
pair<int, int> pos(int d, int size)
{
    if (size == 2)
    {
        if (d == 1)
            return {1, 1};
        if (d == 2)
            return {2, 2};
        if (d == 3)
            return {2, 1};
        if (d == 4)
            return {1, 2};
    }
    int md = size / 2;
    int quarter = md * md;
    if (d <= quarter)
    {
        auto [x, y] = pos(d, md);
        return {x, y};
    }
    else if (d <= 2 * quarter)
    {
        auto [x, y] = pos(d - quarter, md);
        return {x + md, y + md};
    }
    else if (d <= 3 * quarter)
    {
        auto [x, y] = pos(d - 2 * quarter, md);
        return {x + md, y};
    }
    else
    {
        auto [x, y] = pos(d - 3 * quarter, md);
        return {x, y + md};
    }
}
void solve(void)
{
    int n, q;
    cin >> n >> q;
    int size = 1 << n;
    while (q--)
    {
        string s;
        cin >> s;
        if (s[0] == '-')
        {
            int x, y;
            cin >> x >> y;
            cout << (find_value(x, y, size)) << '\n';
        }
        else
        {
            int d;
            cin >> d;
            auto [x, y] = (pos(d, size));
            cout << x << ' ' << y << '\n';
        }
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
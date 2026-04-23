#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
class Solution
{
// cout << fixed << showpoint << setprecision(10);
#define dbg(x) cout << #x << " = " << x << '\n'

    map<pair<int, int>, double> mp;
    double ok(int a, int b)
    {
        if (a <= 0 && b <= 0)
            return 0.5;
        if (a <= 0)
            return 1.0;
        if (b <= 0)
            return 0.0;
        if (mp.find({a, b}) != mp.end())
            return mp[{a, b}];

        double t1 = ok(a - 100, b);
        double t2 = ok(a - 75, b - 25);
        double t3 = ok(a - 50, b - 50);
        double t4 = ok(a - 25, b - 75);
        return mp[{a, b}] = 0.25 * (t1 + t2 + t3 + t4);
    }

public:
    double soupServings(int n)
    {
        if (n > 5000)
            return 1.00;
        return ok(n, n);
    }
};
//-----------------------------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    {
        Solution aa;
        int n;
        cin >> n;
        cout << aa.soupServings(n);
    }
    return 0;
}
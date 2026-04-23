// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  30.07.2025

#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
class Solution
{
// cout << fixed << showpoint << setprecision(10);
#define dbg(x) cout << #x << " = " << x << '\n'
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

    const double eps = 1e-1;
    const int inf = 9e15 + 7;
    const int MOD = 1e9 + 7;
    const int N = 1e9 + 10;

public:
    int reverse(int x)
    {
        int ans = 0;
        if (x < 0)
        {
            x = -x;
            while (x > 0)
            {
                if (ans > (INT_MAX) / 10)
                    return 0;
                ans = ans * 10 + x % 10;
                x /= 10;
            }
            return -ans;
        }
        while (x > 0)
        {
            if (ans > (INT_MAX) / 10)
                return 0;
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
};
//-----------------------------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    {
        Solution aa;
        int x;
        cin >> x;
        cout << aa.reverse(x) << '\n';
    }
    return 0;
}
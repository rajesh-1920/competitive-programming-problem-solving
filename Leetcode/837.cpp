#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
class Solution
{

#define dbg(x) cout << #x << " = " << x << '\n'
public:
    double new21Game(int n, int k, int maxPts)
    {
        if (k == 0)
            return 1;
        vector<double> dp(n + 1);
        dp[0] = 1.0;
        double s = 1.0, sz = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = s / maxPts;
            if (i < k)
                s += dp[i];
            if (i >= maxPts && i - maxPts < k)
                s -= dp[i - maxPts];
        }
        double ans = 0.0;
        for (int i = k; i <= n; i++)
            ans += dp[i];
        return ans;
    }
};
//-----------------------------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(false);
    cout << fixed << showpoint << setprecision(5);
    cin.tie(NULL);
    {
        Solution aa;
        int n, k, mx;
        cin >> n >> k >> mx;
        cout << aa.new21Game(n, k, mx);
    }
    return 0;
}
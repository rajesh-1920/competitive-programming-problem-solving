#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
class Solution
{
// cout << fixed << showpoint << setprecision(10);
#define dbg(x) cout << #x << " = " << x << '\n'

public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second - a.first > b.second - b.first;
    }
    int minimumEffort(vector<vector<int>> &tasks)
    {
        vector<pair<int, int>> vp;
        for (auto &it : tasks)
            vp.push_back({it.front(), it.back()});
        sort(vp.begin(), vp.end(), cmp);
        long long int ans = INT_MAX, l = 0, r = 10000000000;
        while (l <= r)
        {
            long long int m = (l + r) / 2, fl = 1;
            long long int x = m;
            for (auto &it : vp)
            {
                if (m < it.second)
                {
                    fl = 0;
                    break;
                }
                m -= it.first;
            }
            if (fl)
                ans = min(ans, x), r = x - 1;
            else
                l = x + 1;
        }
        return (int)ans;
    }
};
//-----------------------------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    {
     vector<vector<int>> v = {{1, 2}, {2, 4}, {4, 8}};
        vector<vector<int>> v = {{1, 3}, {2, 4}, {10, 11}, {10, 12}, {8, 9}};
        Solution aa;
        cout << aa.minimumEffort(v) << '\n';
    }
    return 0;
}

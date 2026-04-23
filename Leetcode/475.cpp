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

public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        int mx = 0;
        sort(heaters.begin(), heaters.end());
        for (auto &it : houses)
        {
            auto pos1 = lower_bound(heaters.begin(),heaters.end(), it);
            if (pos1 != heaters.end())
            {
                int ds1 = (*pos1) - it;
                if (pos1 != heaters.begin())
                {
                    pos1--;
                    mx = max(mx, min(ds1, it - (*pos1)));
                }
                else
                    mx = max(mx, ds1);
            }
            else
            {
                pos1--;
                mx = max(mx, it - (*pos1));
            }
        }
        return mx;
    }
};
//-----------------------------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    {
        Solution aa;
        vector<int> a = {1, 2, 3, 4}, b = {1, 4};
        cout << aa.findRadius(a, b);
    }
    return 0;
}
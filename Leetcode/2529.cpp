#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
class Solution
{
// cout << fixed << showpoint << setprecision(10);
#define dbg(x) cout << #x << " = " << x << '\n'

public:
    int maximumCount(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1, cn1 = 0;
        if (nums.front() > 1 || nums.back() < 0)
            return nums.size();
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[m] < 0)
                cn1 = max(cn1, m + 1), l = m + 1;
            else
                r = m - 1;
        }
        l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[m] > 0)
                cn1 = max(cn1, (int)(nums.size() - m)), r = m - 1;
            else
                l = m + 1;
        }
        return cn1;
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
        vector<int> v(n);
        for (auto &it : v)
            cin >> it;
        cout << aa.maximumCount(v);
    }
    return 0;
}
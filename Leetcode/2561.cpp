#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
class Solution
{
// cout << fixed << showpoint << setprecision(10);
#define dbg(x) cout << #x << " = " << x << '\n'
public:
    long long minCost(vector<int> &basket1, vector<int> &basket2)
    {
        int m = INT_MAX;
        unordered_map<int, int> frequency_map;
        for (int b1 : basket1)
        {
            frequency_map[b1]++;
            m = min(m, b1);
        }
        for (int b2 : basket2)
        {
            frequency_map[b2]--;
            m = min(m, b2);
        }
        vector<int> merge;
        for (auto [k, c] : frequency_map)
        {
            if (c % 2 != 0)
            {
                return -1;
            }
            for (int i = 0; i < abs(c) / 2; ++i)
            {
                merge.push_back(k);
            }
        }
        nth_element(merge.begin(), merge.begin() + merge.size() / 2,
                    merge.end());
        return accumulate(merge.begin(), merge.begin() + merge.size() / 2, 0ll,
                          [&](long long res, int x) -> long long
                          {
                              return res + min(2 * m, x);
                          });
    }
};
//-----------------------------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    {
        Solution aa;
        vector<int> v1 = {8, 14, 43, 43, 80, 80, 84, 88, 88, 100};
        vector<int> v2 = {8, 14, 32, 32, 42, 42, 68, 68, 84, 100};
        cout << aa.minCost(v1, v2);
    }
    return 0;
}
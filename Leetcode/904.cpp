#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
class Solution
{
// cout << fixed << showpoint << setprecision(10);
#define dbg(x) cout << #x << " = " << x << '\n'

public:
    int totalFruit(vector<int> &fruits)
    {
        int mx = 0, r = 0, l = 0;
        map<int, int> mp;
        while (r < fruits.size())
        {
            mp[fruits[r]]++;
            r++;
            while (mp.size() > 2)
            {
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0)
                    mp.erase(fruits[l]);
                l++;
            }
            mx = max(r - l, mx);
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
        vector<int> v = {1, 2, 3, 2, 2};
        cout << aa.totalFruit(v);
    }
    return 0;
}
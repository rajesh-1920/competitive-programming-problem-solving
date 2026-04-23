#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
class Solution
{
// cout << fixed << showpoint << setprecision(10);
#define dbg(x) cout << #x << " = " << x << '\n'

public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        int ans = 0;
        set<int> st;
        for (int i = 0; i < fruits.size(); i++)
            st.insert(i);
        for (int i = 0; i < fruits.size(); i++)
        {
            for (auto it : st)
            {
                if (baskets[it] >= fruits[i])
                {
                    fruits[i] = 0;
                    st.erase(it);
                    break;
                }
            }
        }
        for (auto it : fruits)
            ans += it != 0;
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
        vector<int> v = {4, 2, 5}, vv = {3, 5, 4};
        cout << aa.numOfUnplacedFruits(v, vv);
    }
    return 0;
}
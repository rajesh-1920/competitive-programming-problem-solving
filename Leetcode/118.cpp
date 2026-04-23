#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
class Solution
{
// cout << fixed << showpoint << setprecision(10);
#define dbg(x) cout << #x << " = " << x << '\n'

public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        vector<int> vv;
        vv.push_back(1);
        ans.push_back(vv);
        for (int i = 1; i < numRows; i++)
        {
            vector<int> v;
            v.push_back(1);
            for (int j = 1; j < i; j++)
            {
                v.push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
            }
            v.push_back(1);
            ans.push_back(v);
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
        vector<vector<int>> ans = aa.generate(5);
        for (auto it : ans)
        {
            for (auto ii : it)
                cout << ii << ' ';
            cout << '\n';
        }
    }
    return 0;
}
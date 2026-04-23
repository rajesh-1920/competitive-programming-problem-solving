#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
class Solution
{
// cout << fixed << showpoint << setprecision(10);
#define dbg(x) cout << #x << " = " << x << '\n'

public:
    bool judgePoint24(vector<int> &cards)
    {
        vector<int> v = cards;
        sort(v.begin(), v.end());
        // do
        // {
        //     for (auto it : v)
        //         cout << it << ' ';
        //     cout << '\n';

        // } while (next_permutation(v.begin(), v.end()));
        string s;
        parenthesis(s, 0, 0);
        for (auto it : part)
            cout << it << '\n';
        return false;
    }
    vector<string> part;
    void parenthesis(string &ans, int c1, int c2)
    {
        if (ans.size() == 8)
        {
            part.push_back(ans);
            return;
        }
        if (c1 < 4)
        {
            ans.push_back('(');
            parenthesis(ans, c1 + 1, c2);
            ans.pop_back();
        }
        if (c2 < c1)
        {
            ans.push_back(')');
            parenthesis(ans, c1, c2 + 1);
            ans.pop_back();
        }
    }
};
//-----------------------------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    {
        Solution aa;
        vector<int> v(4);
        cin >> v[0] >> v[1] >> v[2] >> v[3];
        cout << aa.judgePoint24(v);
    }
    return 0;
}
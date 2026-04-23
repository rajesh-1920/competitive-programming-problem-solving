#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
class Solution
{
// cout << fixed << showpoint << setprecision(10);
#define dbg(x) cout << #x << " = " << x << '\n'

public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        vector<int> v;
        set<pair<int, int>> st;
        int n = mat.size(), m = mat[0].size();
        vector<int> g[n + m - 1];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0, k = i; j < n && k >= 0; j++, k--)
                g[i].push_back(mat[j][k]);
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = i, k = m - 1; j < n && k >= 0; j++, k--)
                g[i + m - 1].push_back(mat[j][k]);
        }
        int i = 0;
        for (auto it : g)
        {
            if (i & 1)
                for (auto ii : it)
                    v.push_back(ii);
            else
                for (int j = it.size() - 1; j >= 0; j--)
                    v.push_back(it[j]);
            i++;
        }
        return v;
    }
};
//-----------------------------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    {
        Solution aa;
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        for (auto &ii : v)
            for (auto &it : ii)
                cin >> it;
        vector<int> ans = aa.findDiagonalOrder(v);
        for (auto it : ans)
            cout << it << ',';
    }
    return 0;
}
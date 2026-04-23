#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
class Solution
{
// cout << fixed << showpoint << setprecision(10);
#define dbg(x) cout << #x << " = " << x << '\n'

public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }
    int numberOfPairs(vector<vector<int>> &points)
    {
        set<pair<int, int>> st;
        int n = points.size();
        sort(points.begin(), points.end(), cmp);
        for (int i = 0; i < n; i++)
        {
            // dbg(i);
            for (int j = i + 1; j < n; j++)
            {
                if (points[i][1] < points[j][1])
                    continue;
                int fl = 1;
                for (int k = 0; k < n; k++)
                {
                    if (k == i || k == j)
                        continue;
                    if (points[i][0] <= points[k][0] &&
                        points[k][0] <= points[j][0])
                        if (points[i][1] >= points[k][1] &&
                            points[k][1] >= points[j][1])
                        {
                            // dbg(j);
                            // dbg(k);
                            // dbg(points[k][0]);

                            fl = 0;
                            break;
                        }
                }
                if (fl)
                    st.insert({min(i, j), max(i, j)});
            }
            // dbg(st.size());
        }
        return st.size();
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
        vector<vector<int>> v(n, vector<int>(2));
        for (auto &it : v)
            cin >> it[0] >> it[1];
        cout << aa.numberOfPairs(v);
    }
    return 0;
}
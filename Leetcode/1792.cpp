#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
class Solution
{
// cout << fixed << showpoint << setprecision(10);
#define dbg(x) cout << #x << " = " << x << '\n'

public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        priority_queue<pair<double, pair<double, double>>> pq;
        for (auto it : classes)
        {
            double up = it[0], dw = it[1];
            pq.push({(up + 1) / (dw + 1) - (up / dw), {up, dw}});
        }
        while (extraStudents--)
        {
            double up = pq.top().second.first, dw = pq.top().second.second;
            pq.pop();
            up++, dw++;
            pq.push({(up + 1) / (dw + 1) - (up / dw), {up, dw}});
        }
        double ans = 0;
        while (!pq.empty())
        {
            double up = pq.top().second.first, dw = pq.top().second.second;
            pq.pop();
            ans += up / dw;
        }
        return ans / (double)(classes.size());
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
        cin >> n;
        cout << aa.maxAverageRatio(v, n);
    }
    return 0;
}
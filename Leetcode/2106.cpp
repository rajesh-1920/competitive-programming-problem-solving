#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
class Solution
{
// cout << fixed << showpoint << setprecision(10);
#define dbg(x) cout << #x << " = " << x << '\n'

public:
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
    {
        int n = 2e5 + 10, kk = k;
        vector<int> v(n, 0);
        for (auto it : fruits)
            v[it[0]] = it[1];
        for (int i = startPos - 2; i >= 0; i--)
            v[i] = v[i + 1] + v[i];
        long long s = 0, ans = 0;
        for (int i = startPos; i < n; i++)
        {
            if (k == -1)
                break;
            s += v[i];
            int t = max(0, i - k);
            k--;
            if (t < startPos)
                ans = max(ans, s + v[t]);
            else
                ans = max(ans, s);
        }
        vector<int> vv(n, 0);
        for (auto it : fruits)
            vv[it[0]] = it[1];

        long long temp = ans;
        for (int i = startPos + 2; i < n; i++)
            vv[i] = vv[i - 1] + vv[i];
        s = 0, ans = 0;
        k = kk;
        for (int i = startPos; i >= 0; i--)
        {
            if (k == -1)
                break;
            s += vv[i];
            int t = min(n - 1, i + k);
            k--;
            if (t > startPos)
                ans = max(ans, s + vv[t]);
            else
                ans = max(ans, s);
        }
        return max(temp, ans);
    }
};
//-----------------------------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    {
        Solution aa;
        vector<vector<int>> fruits = {{0, 9}, {4, 1}, {5, 7}, {6, 2}, {7, 4}, {10, 9}};
        //vector<vector<int>> fruits = {{2, 8}, {6, 3}, {8, 6}};
        cout << aa.maxTotalFruits(fruits, 5, 4);
    }
    return 0;
}
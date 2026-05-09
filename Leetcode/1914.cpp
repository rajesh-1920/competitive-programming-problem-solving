#include <bits/stdc++.h>
using namespace std;
#define Dbg(x) cout << #x << ' ' << " = " << x << '\n';
template <class T>
void dbg(T x)
{
    cout << x << ' ';
}
template <class T, class V>
void dbg(pair<T, V> x)
{
    cout << "{ ";
    dbg(x.first);
    dbg(x.second);
    cout << "},";
}
template <class T>
void dbg(vector<T> x)
{
    cout << "[";
    for (auto &it : x)
        dbg(it);
    cout << "]\n";
}
template <class T>
void dbg(set<T> x)
{
    cout << "[";
    for (auto &it : x)
        dbg(it);
    cout << "]\n";
}
template <class T>
void dbg(multiset<T> x)
{
    cout << "[";
    for (auto &it : x)
        dbg(it);
    cout << "]\n";
}
template <class T, class V>
void dbg(map<T, V> x)
{
    cout << "[";
    for (auto &it : x)
        dbg(it);
    cout << "]\n";
}
template <class T>
void dbg(stack<T> x)
{
    cout << "[";
    while (!x.empty())
        dbg(x.top()), x.pop();
    cout << "]\n";
}
template <class T>
void dbg(queue<T> x)
{
    cout << "[";
    while (!x.empty())
        dbg(x.front()), x.pop();
    cout << "]\n";
}
//-----------------------------------------------------------------------------------------
class Solution
{

public:
    vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k)
    {
        int n = grid.size(), m = grid.front().size();
        int x = n, y = m;
        for (int t = 0; t < min(n / 2, m / 2); t++)
        {
            int t1 = 2 * x + 2 * (y - 2);
            t1 = k % t1;
            while (t1--)
            {
                int i = t, j = t, fl = 1, t2 = grid[t][t];
                while (true)
                {
                    if (fl == 1)
                    {
                        grid[i][j] = grid[i][j + 1], j++;
                        if (j + 1 == m - t)
                            fl = 2;
                    }
                    else if (fl == 2)
                    {
                        grid[i][j] = grid[i + 1][j], i++;
                        if (i + 1 == n - t)
                            fl = -1;
                    }
                    else if (fl == -1)
                    {
                        grid[i][j] = grid[i][j - 1], j--;
                        if (j == t)
                            fl = -2;
                    }
                    else
                    {
                        grid[i][j] = grid[i - 1][j], i--;
                        if (i == t)
                            break;
                    }
                }
                grid[i + 1][j] = t2;
            }
            x -= 2;
            y -= 2;
        }
        return grid;
    }
};
//-----------------------------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    {
        vector<vector<int>> grid = {
            {3970, 1906, 3608, 298, 3072, 3546, 1502, 773, 4388, 3115, 747, 3937},
            {2822, 304, 4179, 1780, 1709, 1058, 3645, 681, 2910, 2513, 4357, 1038},
            {4471, 2443, 218, 550, 2766, 4780, 1997, 1672, 4095, 161, 4645, 3838},
            {2035, 2350, 3653, 4127, 3208, 4717, 4347, 3452, 1601, 3725, 3060, 2270},
            {188, 2278, 81, 3454, 3204, 1897, 2862, 4381, 3704, 2587, 743, 3832},
            {996, 4499, 66, 2742, 1761, 1189, 608, 509, 2344, 3271, 3076, 108},
            {3274, 2042, 2157, 3226, 2938, 3766, 2610, 4510, 219, 1276, 3712, 4143},
            {744, 234, 2159, 4478, 4161, 4549, 4214, 4272, 701, 4376, 3110, 4896},
            {4431, 1011, 757, 2690, 83, 3546, 946, 1122, 2216, 3944, 2715, 2842},
            {898, 4087, 703, 4153, 3297, 2968, 3268, 4717, 1922, 2527, 3139, 1516},
            {1086, 1090, 302, 1273, 2292, 234, 3268, 2284, 4203, 3838, 2227, 3651},
            {2055, 4406, 2278, 3351, 3217, 2506, 4525, 233, 3829, 63, 4470, 3170},
            {3797, 3276, 1755, 1727, 1131, 4108, 3633, 1835, 1345, 1293, 2778, 2805},
            {1215, 84, 282, 2721, 2360, 2321, 1435, 2617, 1202, 2876, 3420, 3034}};
        Solution aa;
        int k = 405548684;
        grid = aa.rotateGrid(grid, k);
        dbg(grid);
    }
    return 0;
}

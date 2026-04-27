#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
class Solution
{
// cout << fixed << showpoint << setprecision(10);
#define dbg(x) cout << #x << " = " << x << '\n'

public:
    void upp(int x, int y, vector<vector<int>> &vv,
             queue<pair<int, int>> &q)
    {
        if (vv[x][y] == 2 || vv[x][y] == 3 || vv[x][y] == 4)
        {
            vv[x][y] == -vv[x][y];
            q.push({x, y});
        }
    }
    void down(int x, int y, vector<vector<int>> &vv,
              queue<pair<int, int>> &q)
    {
        if (vv[x][y] == 2 || vv[x][y] == 5 || vv[x][y] == 6)
        {
            vv[x][y] == -vv[x][y];
            q.push({x, y});
        }
    }
    void left(int x, int y, vector<vector<int>> &vv,
              queue<pair<int, int>> &q)
    {
        if (vv[x][y] == 1 || vv[x][y] == 4 || vv[x][y] == 6)
        {
            vv[x][y] == -vv[x][y];
            q.push({x, y});
        }
    }
    void right(int x, int y, vector<vector<int>> &vv,
               queue<pair<int, int>> &q)
    {
        if (vv[x][y] == 1 || vv[x][y] == 3 || vv[x][y] == 5)
        {
            vv[x][y] == vv[x][y];
            dbg(vv[x][y]);
            q.push({x, y});
        }
    }

    bool hasValidPath(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        vector<vector<int>> vv = grid;
        int n = grid.size(), m = grid.front().size();
        q.push({0, 0});
        vv[0][0] = -vv[0][0];
        while (!q.empty())
        {
            auto [x, y] = q.front();
            if (x == n - 1 && y == m - 1)
                return true;
            q.pop();
            if (vv[x][y] == -1)
            {
                if (y - 1 >= 0)
                    left(x, y - 1, vv, q);
                if (y + 1 < m)
                    right(x, y + 1, vv, q);
            }
            else if (vv[x][y] == -2)
            {
                if (x - 1 >= 0)
                    upp(x - 1, y, vv, q);
                if (x + 1 < n)
                    down(x + 1, y, vv, q);
            }
            else if (vv[x][y] == -3)
            {
                if (x + 1 < n)
                    down(x + 1, y, vv, q);
                if (y - 1 >= 0)
                    left(x, y - 1, vv, q);
            }
            else if (vv[x][y] == -4)
            {
                if (y + 1 < m)
                    right(x, y + 1, vv, q);
                if (x + 1 < n)
                    down(x + 1, y, vv, q);
            }
            else if (vv[x][y] == -5)
            {
                if (x - 1 >= 0)
                    upp(x - 1, y, vv, q);
                if (y - 1 >= 0)
                    left(x, y - 1, vv, q);
            }
            else
            {
                if (x - 1 >= 0)
                    upp(x - 1, y, vv, q);
                if (y + 1 < m)
                    right(x, y + 1, vv, q);
            }
        }
        for (auto it : vv)
        {
            for (auto ii : it)
                cout << ii << ' ';
            cout << '\n';
        }
        return false;
    }
};
//-----------------------------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    {
        Solution aa;
        vector<vector<int>> grid = {{2, 4, 3}, {6, 5, 2}};
        cout << aa.hasValidPath(grid);
    }
    return 0;
}
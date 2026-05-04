#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
class Solution
{
// cout << fixed << showpoint << setprecision(10);
#define dbg(x) cout << #x << " = " << x << '\n'

public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++)
        {
            for (int ii = 0; ii+1 < n - 2*i; ii++)
            {
                int t = matrix[i][i], x = i, y = i, dir = -1, cnt = 20;
                while (true)
                {

                    if (dir == -1)
                    {
                        if (x + 1 < n - i)
                            matrix[x][y] = matrix[x + 1][y], x++;
                        else
                            dir = 2;
                    }
                    else if (dir == 1)
                    {
                        if (x - 1 >= i)
                            matrix[x][y] = matrix[x - 1][y], x--;
                        else
                            dir = -2;
                    }
                    else if (dir == 2)
                    {
                        if (y + 1 < n - i)
                            matrix[x][y] = matrix[x][y + 1], y++;
                        else
                            dir = 1;
                    }
                    else
                    {
                        matrix[x][y] = matrix[x][y - 1], y--;
                    }
                    if (x == i && y == i)
                        break;
                }
                matrix[i][i + 1] = t;
            }
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
        vector<vector<int>> matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
        aa.rotate(matrix);
        for (auto &it : matrix)
        {
            for (auto &ii : it)
                cout << ii << ' ';
            cout << '\n';
        }
    }
    return 0;
}

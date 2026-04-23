#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
class Solution
{
// cout << fixed << showpoint << setprecision(10);
#define dbg(x) cout << #x << " = " << x << '\n'

public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                for (int x = i + 1; x < 9; x++)
                    if (board[i][j] == board[x][j])
                        return false;
                for (int x = i - 1; x >= 0; x--)
                    if (board[i][j] == board[x][j])
                        return false;
                for (int x = j - 1; x >= 0; x--)
                    if (board[i][j] == board[i][x])
                        return false;
                for (int x = j + 1; x < 9; x++)
                    if (board[i][j] == board[i][x])
                        return false;

                for (int x = i / 3 * 3; x < 3 + i / 3 * 3; x++)
                    for (int y = j / 3 * 3; y < 3 + j / 3 * 3; y++)
                    {
                        if (i == x && j == y)
                            continue;
                        if (board[i][j] == board[x][y])
                            return false;
                    }
            }
        return true;
    }
};
//-----------------------------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    {
        Solution aa;
        vector<vector<char>> board(9, vector<char>(9));
        for (auto &it : board)
            for (auto &i : it)
                cin >> i;
        cout << aa.isValidSudoku(board);
    }
    return 0;
}
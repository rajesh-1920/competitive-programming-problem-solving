// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  16.04.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
// #define int long long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

// const double eps = 1e-1;
// const int inf = 9e16 + 7;
// const int MOD = 1e9 + 7;

// //------------------------------------------(N queens)------------------------------------------
// bool issafe(vector<string> &board, int &row, int &col)
// {
//     for (int i = 0; i < board.size(); i++)
//         if (board[i][col] == 'Q' || board[row][i] == 'Q')
//             return false;
//     for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
//         if (board[i][j] == 'Q')
//             return false;
//     for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++)
//         if (board[i][j] == 'Q')
//             return false;
//     return true;
// }

// void place(vector<string> &board, int row, vector<vector<string>> &ans)
// {
//     if (row == board.size())
//     {
//         ans.push_back(board);
//         return;
//     }
//     for (int i = 0; i < board.size(); i++)
//     {
//         if (issafe(board, row, i))
//         {
//             board[row][i] = 'Q';
//             place(board, row + 1, ans);
//             board[row][i] = '.';
//         }
//     }
// }

// void solve(void)
// {
//     int n;
//     cin >> n;
//     vector<string> board(n, string(n, '.'));
//     vector<vector<string>> ans;
//     place(board, 0, ans);
//     dbg(ans.size());
//     for (auto v : ans)
//     {
//         for (auto it : v)
//         {
//             for (auto ii : it)
//                 cout << ii << ' ';
//             cout << '\n';
//         }

//         cout << '\n';
//         cout << '\n';
//     }
// }
// //-----------------------------------------------------------------------------------------
//-----------------------------(Suduko)----------------------------------------------------

bool issafe(int row, int col, int val, vector<vector<int>> &suduko)
{
    for (int i = 0; i < 9; i++)
        if (suduko[i][col] == val || suduko[row][i] == val)
            return false;
    row = (row / 3) * 3;
    col = (col / 3) * 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (suduko[i + row][j + col] == val)
                return false;
    return true;
}
bool place(int row, int col, vector<vector<int>> &suduko)
{
    if (row == suduko.size())
        return true;
    if (suduko[row][col])
    {
        if (col == suduko.size() - 1)
            return place(row + 1, 0, suduko);
        else
            return place(row, col + 1, suduko);
    }

    for (int i = 1; i <= 9; i++)
    {
        if (issafe(row, col, i, suduko))
        {
            suduko[row][col] = i;
            bool fl = false;
            if (col == 8)
                fl |= place(row + 1, 0, suduko);
            else
                fl |= place(row, col + 1, suduko);
            if (fl)
                return true;
            suduko[row][col] = 0;
        }
    }
    return false;
}

void solve()
{
    vector<vector<int>> suduko = {
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 4, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 5, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 6, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 7, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 8, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 9}};

    int cc = 0;
    if (place(0, 0, suduko))
    {
        for (auto it : suduko)
        {
            int cnt = 0;
            if (cc % 3 == 0)
            {
                for (int i = 0; i < 25; i++)
                    cout << '-';
                cout << '\n';
            }
            for (auto ii : it)
            {
                if (cnt % 3 == 0)
                    cout << '|' << ' ';
                cout << ii << ' ';
                cnt++;
                if (cnt == 9)
                    cout << '|' << ' ';
            }
            cout << '\n';
            cc++;
            if (cc == 9)
            {
                for (int i = 0; i < 25; i++)
                    cout << '-';
                cout << '\n';
            }
        }
    }
    else
    {
        cout << "Solve not possible\n";
    }
}

//-----------------------------(Suduko)----------------------------------------------------

signed main()
{
    // cout << fixed << showpoint << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1, T;
    // cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}
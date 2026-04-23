#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
class Solution
{
// cout << fixed << showpoint << setprecision(10);
#define dbg(x) cout << #x << " = " << x << '\n'

public:
  int ok(int i, int f1x, int f1y, int f2x, int f2y,
         vector<pair<int, int>> &grid, string &word,
         vector<vector<vector<vector<vector<int>>>>> &dp)
  {
    if (i == word.size())
      return 0;
    // if (dp[i][f1x][f2x][f1y][f2y] != -1)
    //     return dp[i][f1x][f2x][f1y][f2y];
    int x = grid[word[i] - 'A'].first, y = grid[word[i] - 'A'].second;
    int ans = ok(i + 1, x, y, f2x, f2y, grid, word, dp) + abs(x - f1x) +
              abs(y - f1y);
    ans = min(ans, ok(i + 1, f1x, f1y, x, y, grid, word, dp) +
                       abs(x - f2x) + abs(y - f2y));
    // return dp[i][f1x][f2x][f1y][f2y] = ans;
    return ans;
  }
  int minimumDistance(string word)
  {
    vector<pair<int, int>> grid = {
        {0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5}, {3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {4, 0}, {4, 1}};
    int ans = INT_MAX;
    for (int i1 = 0; i1 < 5; i1++)
      for (int j1 = 0; j1 < 6; j1++)
        for (int i2 = 0; i2 < 5; i2++)
          for (int j2 = 0; j2 < 6; j2++)
          {
            vector<vector<vector<vector<vector<int>>>>> dp(
                word.size(),
                vector<vector<vector<vector<int>>>>(
                    6, vector<vector<vector<int>>>(
                           5, vector<vector<int>>(
                                  6, vector<int>(5, -1)))));
            ans = min(ans, ok(0, i1, j1, i2, j2, grid, word, dp));
          }
    return ans;
  }
};
//-----------------------------------------------------------------------------------------
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  {
    Solution aa;
    cout << aa.minimumDistance("LSGQE");
  }
  return 0;
}
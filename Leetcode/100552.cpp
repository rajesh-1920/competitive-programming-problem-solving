// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  01.02.2025

#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
class Solution
{
    typedef long long int ll;
// cout << fixed << showpoint << setprecision(10);
#define dbg(x) cout << #x << " = " << x << '\n'
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

    const double eps = 1e-1;
    const ll inf = 9e15 + 7;
    const ll MOD = 1e9 + 7;
    const ll N = 1e9 + 10;

public:
    vector<bool> palindromePath(int n, vector<vector<int>> &edges, string s, vector<string> &queries)
    {
        vector<vector<int>> g(n + 5);
        for (auto &it : edges)
            g[it[0]].push_back(it[1]), g[it[1]].push_back(it[0]);
        
    }
};
//-----------------------------------------------------------------------------------------
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    {
        Solution aa;
        int n = 4;
        vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}};
        string s = "abca";
        vector<string> queries = {"query 1 2", "update 0 b",
                                  "query 2 3", "update 3 a", "query 1 3"};

        vector<bool> ans = aa.palindromePath(n, edges, s, queries);
        for (auto it : ans)
            cout << it << ' ';
    }
    return 0;
}
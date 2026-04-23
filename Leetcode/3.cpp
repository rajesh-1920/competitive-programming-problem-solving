// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  30.07.2025

#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
class Solution
{
// cout << fixed << showpoint << setprecision(10);
#define dbg(x) cout << #x << " = " << x << '\n'
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0, i = 0, j = 0;
        vector<int> mp(100000, 0);
        while (i < s.size() && j < s.size())
        {
            mp[s[i]]++;
            while (mp[s[i]] > 1)
            {
                mp[s[j]]--;
                j++;
            }
            i++;
            ans = max(ans, i - j);
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
        string s;
        cin >> s;
        cout << aa.lengthOfLongestSubstring(s) << '\n';
    }
    return 0;
}
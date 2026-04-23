#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
class Solution
{
// cout << fixed << showpoint << setprecision(10);
#define dbg(x) cout << #x << " = " << x << '\n'
public:
    string longestPalindrome(string s)
    {
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            int l = i, r = i, ll = i - 1, rr = i, cnt = 0, fl = 0;
            while (true)
            {
                if (cnt == 0)
                {
                    if (l == -1 || r == s.size() || s[l] != s[r])
                        cnt = 1;
                    else
                        l--, r++;
                }
                if (fl == 0)
                {
                    if (ll == -1 || rr == s.size() || s[ll] != s[rr])
                        fl = 1;
                    else
                        ll--, rr++;
                }
                if (cnt == 1 && fl == 1)
                    break;
            }
            l++, r--;
            ll++, rr--;
            if (r - l + 1 > rr - ll + 1)
            {
                if (r - l + 1 > ans.size())
                    ans = s.substr(l, r - l + 1);
            }
            else if (rr - ll + 1 > ans.size())
                ans = s.substr(ll, rr - ll + 1);
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
        cout << aa.longestPalindrome("cbbd");
    }
    return 0;
}
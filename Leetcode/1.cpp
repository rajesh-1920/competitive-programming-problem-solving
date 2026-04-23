// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  04.01.2025

#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
class Solution
{
    typedef long long int ll;
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
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        map<ll, vector<int>> mp;
        for (ll i = 0; i < nums.size(); i++)
            mp[nums[i]].push_back(i);

        for (int i = 0; i < nums.size(); i++)
        {
            ll need = target - nums[i];
            if (need == nums[i])
            {
                if (mp[need].size() > 1)
                {
                    ans.push_back(mp[need].back());
                    mp[need].pop_back();
                    ans.push_back(mp[need].back());
                }
            }
            else if (mp.find(need) != mp.end())
            {
                ans.push_back(i);
                ans.push_back(mp[need].back());
            }
            if (ans.size())
                break;
        }
        return ans;
    }
};
//-----------------------------------------------------------------------------------------
void solve(void)
{
    Solution aa;
    vector<int> v;
    int n;
    while (cin >> n)
    {
        v.push_back(n);
    }
    int t = v.back();
    v.pop_back();
    vector<int> an = aa.twoSum(v, t);
    for (auto it : an)
        cout << it << ' ';
}
//-----------------------------------------------------------------------------------------
int main()
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
// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  05.01.2025

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
    bool isValid(string s)
    {
        bool ans = true;
        stack<char> st;
        for (auto it : s)
        {
            if (it == '(' || it == '{' || it == '[')
                st.push(it);
            else
            {
                if (st.size() == 0)
                {
                    ans = false;
                    break;
                }
                if (it == ')')
                    if (st.top() != '(')
                        ans = false;
                if (it == '}')
                    if (st.top() != '{')
                        ans = false;
                if (it == ']')
                    if (st.top() != '[')
                        ans = false;
                st.pop();
            }
        }
        if (st.size())
            ans = false;
        return ans;
    }
};
//-----------------------------------------------------------------------------------------
void solve(void)
{
    Solution aa;
    string s;
    cin >> s;
    cout << aa.isValid(s);
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
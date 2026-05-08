#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
class Solution
{
// cout << fixed << showpoint << setprecision(10);
#define dbg(x) cout << #x << " = " << x << '\n'

public:
    int ok(string &s)
    {
        int n = 0;
        for (auto &it : s)
            n = n * 10 + (it - '0');
        return n;
    }
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (auto &it : tokens)
        {
            if (it.back() >= '0' && it.back() <= '9')
                st.push(ok(it));
            else
            {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                if (it == "+")
                    st.push(x + y);
                else if (it == "-")
                    st.push(y - x);
                else if (it == "*")
                    st.push(y * x);
                else
                    st.push(y / x);
            }
        }
        return st.top();
    }
};
//-----------------------------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    {
        Solution aa;
        vector<string> v = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
        cout << aa.evalRPN(v);
    }
    return 0;
}

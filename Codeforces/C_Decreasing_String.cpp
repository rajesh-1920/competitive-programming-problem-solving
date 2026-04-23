// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  28.08.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
#define int long long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
struct stc
{
    int vl, l, r;
    bool operator<(const stc &other) const
    {
        if (vl == other.vl)
            return l < other.l;
        return vl < other.vl;
    }
};
void solve(void)
{
    int n;
    string s;
    cin >> s >> n;
    int sz = s.size(), t = s.size() - 1;

    set<int> st;
    priority_queue<stc> pq;
    for (int i = 0; i < sz; i++)
    {
        st.insert(i);
        if (i + 1 < n)
        {
            stc x;
            x.l = -i, x.r = -i - 1;
            if (s[i + 1] < s[i])
                x.vl = 1;
            else
                x.vl = 0;
            pq.push(x);
        }
    }
    while (n > sz)
    {
        sz += t;
        t--;
        stc x = pq.top();
        pq.pop();
        int l = -x.l, r = -x.r;
        if (x.vl)
        {
            s[l] = '*';
            st.erase(l);
            auto it = st.lower_bound(l);
            if (it != st.begin())
            {
                it--;
                l = *it;
                x.l = -l;
                if (s[l] > s[r])
                    x.vl = 1;
                else
                    x.vl = 0;
                pq.push(x);
            }
        }
        else
        {
            s[r] = '*';
            st.erase(r);
            auto it = st.lower_bound(r);
            if (it != st.end())
            {
                r = *it;
                x.r = -r;
                if (s[l] > s[r])
                    x.vl = 1;
                else
                    x.vl = 0;
                pq.push(x);
            }
        }
    }

    t = sz - n;
    int x = s.size() - 1;
    while (t)
    {
        if (s[x] != '*')
            t--;
        x--;
    }
    while (s[x] == '*')
        x--;
    cout << s[x];
}
//-----------------------------------------------------------------------------------------
signed main()
{
    // cout << fixed << showpoint << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1, T;
    cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}
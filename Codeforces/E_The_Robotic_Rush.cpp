// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  18.01.2026

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
const int inf = 9e15 + 7;
const int MOD = 1e8;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
void solve(void)
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> robo(n);
    for (auto &it : robo)
        cin >> it;
    set<int> st;
    for (int i = 0, x; i < m; i++)
    {
        cin >> x;
        st.insert(x);
    }
    string s;
    cin >> s;
    map<int, int> left, right;
    int p = 0;
    for (int i = 0; i < k; i++)
    {
        if (s[i] == 'L')
            p--;
        else
            p++;
        if (p < 0 && left.find(-p) == left.end())
            left[-p] = i;
        else if (right.find(p) == right.end())
            right[p] = i;
    }

    for (int i = 0; i < n; i++)
    {
        int ltime = inf, rtime = inf;
        if (st.lower_bound(robo[i]) != st.begin())
        {
            int x = robo[i] - (*(--st.lower_bound(robo[i])));
            if (left.lower_bound(x) != left.end())
                ltime = left[x];
        }
        if (st.lower_bound(robo[i]) != st.end())
        {
            int x = (*(st.lower_bound(robo[i]))) - robo[i];
            if (right.lower_bound(x) != right.end())
                rtime = right[x];
        }
        robo[i] = min(ltime, rtime);
    }
    map<int, int> cnt;
    for (auto &it : robo)
        cnt[it]++;
    for (int i = 0; i < k; i++)
    {
        if (n)
            n -= cnt[i];
        n = max(0ll, n);
        cout << n << ' ';
    }
    cout << '\n';
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
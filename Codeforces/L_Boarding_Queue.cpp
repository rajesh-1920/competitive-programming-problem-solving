// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  28.02.2025

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n'
#define int long long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int r, c, n, p;
    cin >> r >> c >> n >> p;
    vector<vector<int>> a(r + 5, vector<int>(c + 5, 0));
    int si, sj;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == p)
                si = i, sj = j;
        }
    set<int> st;
    st.insert(a[si - 1][sj]);
    st.insert(a[si + 1][sj]);
    st.insert(a[si][sj + 1]);
    st.insert(a[si][sj - 1]);
    int cnt = 0;
    while (true)
    {
        p--;
        if (p == 0)
            break;
        cnt++;
        if (a[si - 1][sj] == p)
        {
            si--;
            if (a[si - 1][sj] && a[si - 1][sj] + cnt <= n)
                st.insert(a[si - 1][sj] + cnt);
            if (a[si][sj - 1] && a[si][sj - 1] + cnt <= n)
                st.insert(a[si][sj - 1] + cnt);
            if (a[si][sj + 1] && a[si][sj + 1] + cnt <= n)
                st.insert(a[si][sj + 1] + cnt);
        }
        else if (a[si + 1][sj] == p)
        {
            si++;
            if (a[si + 1][sj] && a[si + 1][sj] + cnt <= n)
                st.insert(a[si + 1][sj] + cnt);
            if (a[si][sj - 1] && a[si][sj - 1] + cnt <= n)
                st.insert(a[si][sj - 1] + cnt);
            if (a[si][sj + 1] && a[si][sj + 1] + cnt <= n)
                st.insert(a[si][sj + 1] + cnt);
        }
        else if (a[si][sj + 1] == p)
        {
            sj++;
            if (a[si - 1][sj] && a[si - 1][sj] + cnt <= n)
                st.insert(a[si - 1][sj] + cnt);
            if (a[si + 1][sj] && a[si + 1][sj] + cnt <= n)
                st.insert(a[si + 1][sj] + cnt);
            if (a[si][sj + 1] && a[si][sj + 1] + cnt <= n)
                st.insert(a[si][sj + 1] + cnt);
        }
        else
        {
            sj--;
            if (a[si - 1][sj] && a[si - 1][sj] + cnt <= n)
                st.insert(a[si - 1][sj] + cnt);
            if (a[si + 1][sj] && a[si + 1][sj] + cnt <= n)
                st.insert(a[si + 1][sj] + cnt);
            if (a[si][sj - 1] && a[si][sj - 1] + cnt <= n)
                st.insert(a[si][sj - 1] + cnt);
        }
    }
    st.insert(0);
    st.erase(0);
    cout << st.size() << '/' << (n - 1);
}
//-----------------------------------------------------------------------------------------
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
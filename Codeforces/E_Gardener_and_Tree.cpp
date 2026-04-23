// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  10.01.2025

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
const int N = 3e5 + 10;
//-----------------------------------------------------------------------------------------
void solve(void)
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n + 1);
    vector<int> in(n + 1, 0);
    set<int> st;
    for (int i = 1, x, y; i < n; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
        in[x]++, in[y]++;
    }
    if (n == 1)
    {
        cout << (!k) << '\n';
        return;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (in[i] == 1)
            q.push(i), st.insert(i);
        else
            st.insert(i);
    while (k--)
    {
        if (q.empty())
            break;
        int x = q.size();
        while (x--)
        {
            int t = q.front();
            st.insert(t);
            st.erase(t);
            q.pop();
            for (auto it : v[t])
            {
                in[it]--;
                if (in[it] == 1)
                    q.push(it);
            }
        }
    }
    cout << st.size() << '\n';
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
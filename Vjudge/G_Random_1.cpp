// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  25.03.2025

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
    string a, b;
    cin >> a >> b;
    int j = 0, fl = 1, cnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b[j])
            j++;
        else
            cnt++;
    }
    if (cnt > 1)
    {
        cout << 0;
        return;
    }
    set<int> ans;
    int to;
    if (cnt == 0)
    {
        to = a.size() - 1;
        ans.insert(a.size());
    }
    else
    {
        j = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[j])
            {
                to = i;
                ans.insert(i + 1);
                break;
            }
            j++;
        }
    }
    for (int i = to; i < a.size(); i++)
    {
        if (a[i] != a[to])
            break;
        ans.insert(i + 1);
    }
    for (int i = to; i >= 0; i--)
    {
        if (a[i] != a[to])
            break;
        ans.insert(i + 1);
    }
    cout << ans.size() << '\n';
    for (auto it : ans)
        cout << it << ' ';
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
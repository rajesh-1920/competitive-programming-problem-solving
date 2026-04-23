// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  12.05.2025

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
    int k;
    string s;
    cin >> k >> s;
    set<int> q;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            q.insert(i);
    }
    q.insert(s.size());

    int i = 0, j = 0, ans = 0, cnt = 0, c1 = 0;
    while (s.size() != j)
    {
        if (s[j] == '1')
            break;
        j++;
        cnt++;
    }
    if (k == 0 && cnt == s.size())
        ans = cnt * (cnt + 1) / 2;
    else if (k == 0)
    {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                ans += (cnt * (cnt + 1) / 2), cnt = 0;
            else
                cnt++;
        }
    }
    else
        while (i < s.size() && j < s.size())
        {
            if (c1 < k)
            {
                if (s[j] == '1')
                {
                    c1++;
                    q.erase(j);
                }
                j++;
            }
            if (c1 == k)
            {
                int next = *q.begin();
                cnt += next - j;
                // dbg(c1);
                // dbg(cnt);
                // dbg(j);
                ans += (1 + (cnt * (cnt + 1) / 2));
                cnt = 0;
                i++;
                c1--;
                while (i < s.size())
                {
                    if (s[i] == '1')
                        break;
                    cnt++;
                    i++;
                }
            }
        }
    cout << ans << '\n';
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
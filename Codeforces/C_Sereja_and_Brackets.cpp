// Author:  Rajesh Biswas
// CF    :  rajesh_1920
// Date  :  17.01.2026

#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)-----------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
// #define int long int
#define fi first
#define sc second

#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()

const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e8;
const int N = 1e5 + 10;
//------------------------------(solve)----------------------------------------------------
struct stc
{
    int l, r, ind;
};
int len = 1000000;
bool cmp(stc &a, stc &b)
{
    if (a.l / len == b.l / len)
        return a.r > b.r;
    return a.l / len < b.l / len;
}
void solve(void)
{
    string s;
    cin >> s;
    int n = s.size();
    len = sqrt(n) + 1;
    int q;
    cin >> q;
    vector<stc> query(q);
    for (int i = 0; i < q; i++)
    {
        cin >> query[i].l >> query[i].r;
        query[i].l--, query[i].r--;
        query[i].ind = i;
    }
    sort(all(query), cmp);
    vector<int> ans(q);
    int curl = 0, curr = -1, cleft = 0, cright = 0, cans = 0;
    vector<int> cont(n + 5, -1);
    set<int> stl, str;
    for (auto &it : query)
    {
        while (curr < it.r)
        {
            curr++;
            if (s[curr] == ')')
                if (cleft > 0)
                {
                    cleft--, cans++;
                    int t = *(--stl.end());
                    stl.erase(t);
                    cont[t] = curr;
                    cont[curr] = t;
                }
                else
                    cright++, str.insert(curr);
            else
                cleft++, stl.insert(curr);
        }
        while (curl > it.l)
        {
            curl--;
            if (s[curl] == '(')
                if (cright > 0)
                {
                    cans++, cright--;
                    int t = *str.begin();
                    str.erase(str.begin());
                    cont[curl] = t;
                    cont[t] = curl;
                }
                else
                    cleft++, stl.insert(curl);
            else
                cright++, str.insert(curl);
        }
        while (curr > it.r)
        {
            if (s[curr] == ')')
                if (cont[curr] != -1)
                {
                    cleft++, cans--;
                    stl.insert(cont[curr]);
                    cont[cont[curr]] = -1;
                    cont[curr] = -1;
                }
                else
                    cright--, str.erase(curr);
            else
                cleft--, stl.erase(curr);
            curr--;
        }
        while (curl < it.l)
        {
            if (s[curl] == '(')
                if (cont[curl] != -1)
                {
                    cans--, cright++;
                    str.insert(cont[curl]);
                    cont[cont[curl]] = -1;
                    cont[curl] = -1;
                }
                else
                    cleft--, stl.erase(curl);
            else
                cright--, str.erase(curl);
            curl++;
        }
        ans[it.ind] = cans * 2;
    }
    for (auto &it : ans)
        cout << it << '\n';
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
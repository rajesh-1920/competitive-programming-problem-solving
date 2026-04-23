// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  19.10.2025

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
void solve(void)
{
    int n;
    cin >> n;
    vector<int> v(n);
    set<int> st, temp;
    for (int i = 1; i <= n; i++)
        st.insert(i), temp.insert(i);
    while (temp.size() > 1)
    {
        int pi = *temp.begin();
        temp.erase(temp.begin());
        int pj = *temp.begin();
        temp.erase(temp.begin());

        int pimodpj, pjmodpi;
        cout << "? " << pi << ' ' << pj << '\n';
        cin >> pimodpj;
        cout << "? " << pj << ' ' << pi << '\n';
        cin >> pjmodpi;

        if (pimodpj < pjmodpi)
        {
            temp.insert(pi);
            v[pj - 1] = pjmodpi;
            st.erase(pjmodpi);
        }
        else
        {
            temp.insert(pj);
            v[pi - 1] = pimodpj;
            st.erase(pimodpj);
        }
    }
    cout << "! ";
    v[(*temp.begin()) - 1] = *st.begin();
    for (auto &it : v)
        cout << it << ' ';
    cout << '\n';
}
//-----------------------------------------------------------------------------------------
signed main()
{
    // cout << fixed << showpoint << setprecision(10);
    int test = 1, T;
    // cin >> test;
    for (T = 1; T <= test; T++)
    {
        // cout << "Case " << T << ": ";
        solve();
    }
    return 0;
}
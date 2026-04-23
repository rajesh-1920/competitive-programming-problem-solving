// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  28.04.2025

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
    int n;
    string s;
    cin >> n >> s;
    if (n == 2)
    {
        if (s == "AB")
        {
            cout << "Alice\n";
            return;
        }
        else if (s == "BA")
        {
            cout << "Bob\n";
            return;
        }
    }

    vector<int> v(n);
    set<int> a, b;
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == 'A')
            a.insert(i);
        else
            b.insert(i);
    }
    while (true)
    {
        if (a.size() <= 1)
        {
            cout << "Bob\n";
            return;
        }
        if (b.size() <= 1)
        {
            cout << "Alice\n";
            return;
        }
        auto it = --a.end();
        auto itb = --b.end();
        if (*(it) == n)
        {
            if ((*a.begin() == 1))
            {
                cout << "Alice\n";
                return;
            }
            it--;
            if (*it < *(itb))
            {
                cout << "Bob\n";
                return;
            }
            a.insert(*(itb));
            b.erase(itb);
        }
        else
        {
            if (*it < *(itb))
            {
                cout << "Bob\n";
                return;
            }
            a.insert(*(itb));
            b.erase(itb);
        }
    }
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
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
// Function to compute LPS array
vector<int> computeLPS(string &pattern)
{
    int m = pattern.size();
    vector<int> lps(m, 0); // LPS array initialize with 0
    int j = 0;             // length of previous longest prefix suffix
    for (int i = 1; i < m;)
    {
        if (pattern[i] == pattern[j])
        {
            j++;
            lps[i] = j;
            i++;
        }
        else if (j != 0)
            j = lps[j - 1]; // use previous LPS to avoid re-comparison
        else
            lps[i++] = 0;
    }
    return lps;
}

bool match(string &text, string &pattern)
{
    vector<int> lps = computeLPS(pattern);
    int n = text.size();
    int m = pattern.size();
    int i = 0, j = 0;
    while (i < n)
    {
        if (text[i] == pattern[j])
            i++, j++;
        if (j == m)
            return true; // pattern found at index i-j
        if (i < n && text[i] != pattern[j])
        {
            if (j != 0)
                j = lps[j - 1]; // use LPS to skip characters
            else
                i++;
        }
    }
    return false;
}
//------------------------------(solve)----------------------------------------------------

void solve(void)
{
    string s;
    cin >> s;
    if (s.size() <= 2)
    {
        cout << "Just a legend\n";
        return;
    }
    vector<int> lps = computeLPS(s);
    int n = s.size();

    vector<int> borders;
    int len = lps[n - 1];

    while (len > 0)
    {
        borders.push_back(len);
        len = lps[len - 1];
    }
    string t = s.substr(1, s.size() - 2);
    sort(rall(borders));
    for (int x : borders)
    {
        string pre = s.substr(0, x);
        if (match(t, pre))
        {
            cout << pre << '\n';
            return;
        }
    }
    cout << "Just a legend\n";
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
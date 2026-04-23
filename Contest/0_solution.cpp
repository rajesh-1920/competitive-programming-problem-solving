// g++ -O2 -std=gnu++17 0_solution.cpp -o sol
// Get-Content 0_input.txt | ./sol | Out-File 0_output.txt

// Author:  Rajesh Biswas
// CF    :  rajesh-1920
// Date  :  18.10.2025

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
    string s;
    cin >> n >> s;
    if (s.back() == 'A')
    {
        cout << "Alice\n";
        return;
    }
    int b = 0, a = 0;
    while (s.size() && s.back() == 'B')
        b++, s.pop_back();
    while (s.size() && s.back() == 'A')
        a++, s.pop_back();
    cout << (a > b ? "Alice\n" : "Bob\n");
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
        cout << "Case #" << T << ": ";
        solve();
    }
    return 0;
}
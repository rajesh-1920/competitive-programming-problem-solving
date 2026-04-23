#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int x;
    cout << "digit\n"; // 1
    cin >> x;
    cout << "digit\n"; // 2
    cin >> x;
    cout << "add -8\n"; // 3
    cin >> x;
    cout << "add -4\n"; // 4
    cin >> x;
    cout << "add -2\n"; // 5
    cin >> x;
    cout << "add -1\n"; // 6
    cin >> x;
    cout << "mul " << n << '\n'; // 7
    cin >> x;
    cout << "!\n";
    cin >> x;
}
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

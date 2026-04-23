#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    cin >> test;
    for (int T = 1; T <= test; T++)
    {
        int n, z, ans = 0;
        cin >> n >> z;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            ans = max(ans, (x | z));
        }
        cout << ans << '\n';
    }
    return 0;
}
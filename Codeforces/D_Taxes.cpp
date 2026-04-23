#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    if (n & 1)
    {
        int fl = 1;
        for (int i = 3; i * i <= n + 5; i += 2)
            if (n % i == 0 && n != i)
            {
                fl = 0;
                break;
            }
        if (fl)
            cout << 1;
        else
        {
            fl = 1;
            n -= 2;
            for (int i = 3; i * i <= n + 5; i += 2)
                if (n % i == 0 && n != i)
                {
                    fl = 0;
                    break;
                }
            if (fl)
                cout << 2;
            else
                cout << (n > 3 ? 3 : 1) << '\n';
        }
    }
    else
        cout << (n > 2 ? 2 : 1) << '\n';
    return 0;
}
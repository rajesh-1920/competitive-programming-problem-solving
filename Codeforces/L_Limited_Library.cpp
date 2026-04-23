#include <bits/stdc++.h>
#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std;
#define int long long

signed main()
{
    FAST_IO;
    // start
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    priority_queue<int> self, boi, ans, temp;
    while (n--)
    {
        int t;
        cin >> t;
        self.push(t);
    }
    while (m--)
    {
        int t;
        cin >> t;
        boi.push(t);
    }

    while (true)
    {
        if (boi.empty() || self.empty())
            break;
        int t = y;
        while (t--)
        {
            if (boi.empty())
                break;
            while (boi.top() > self.top())
            {
                temp.push(boi.top());
                boi.pop();
                if (boi.empty())
                    break;
            }
            if (boi.empty())
                break;
            boi.pop();
        }
        ans.push(self.top());
        self.pop();
    }
    while (!self.empty())
    {
        ans.push(self.top());
        self.pop();
    }
    while (!boi.empty())
    {
        temp.push(boi.top());
        boi.pop();
    }

    while (true)
    {
        if (temp.empty() || ans.empty())
            break;
        int t = x - y;
        while (t--)
        {
            if (temp.empty())
                break;
            if (temp.top() > ans.top())
            {
                cout << "impossible\n";
                return 0;
            }
            temp.pop();
        }
        ans.pop();
    }
    if (temp.empty())
        cout << ans.size() << "\n";
    else
        cout << "impossible\n";
    return 0;
}
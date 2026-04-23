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
    int n, q;
    cin >> n >> q;
    vector<int> ans(n, 0), capa(n), next(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> capa[i];
        if (!st.empty())
        {
            while (capa[st.top()] < capa[i])
            {
                next[st.top()] = i;
                st.pop();
                if (st.empty())
                    break;
            }
        }
        st.push(i);
    }

    while (q--)
    {
        char ch;
        cin >> ch;
        if (ch == '?')
        {
            int l;
            cin >> l;
            l--;
            cout << ans[l] << '\n';
        }
        else
        {
            int l, w;
            cin >> l >> w;
            l--;
            if (next[l] != -1)
            {
                if (ans[next[l]] == capa[next[l]])
                    next[l] = next[next[l]];
            }
            while (w > 0)
            {
                if (w + ans[l] <= capa[l])
                    ans[l] += w, w = 0;
                else
                {
                    w -= capa[l] - ans[l];
                    ans[l] = capa[l];
                    l = next[l];
                    if (l == -1)
                        break;
                }
                if (next[l] != -1)
                {
                    if (ans[next[l]] == capa[next[l]])
                        next[l] = next[next[l]];
                }
            }
        }
    }
    return 0;
}
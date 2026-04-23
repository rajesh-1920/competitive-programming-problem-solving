// Author:  Rajesh Biswas (fixed)
// Date  :  19.10.2025  (updated)
#include <bits/stdc++.h>
using namespace std;
#define int long long
const long long INF = (long long)9e18;

struct State
{
    // GPT
    long long cost;
    int x, y;
    int dir; // 0=up,1=right,2=down,3=left,4=none(start)
    int cnt; // consecutive moves in `dir` (0..3). we keep cnt>=0 (0 only for start)
    bool operator>(const State &o) const
    {
        return cost > o.cost;
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m))
        return 0;
    vector<string> grid(n);
    int si = -1, sj = -1, ei = -1, ej = -1;
    for (int i = 0; i < n; ++i)
    {
        cin >> grid[i];
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 'S')
            {
                si = i;
                sj = j;
            }
            if (grid[i][j] == 'T' || grid[i][j] == 'E')
            {
                ei = i;
                ej = j;
            } // accept T or E
        }
    }
    // directions: up, right, down, left
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    // dist[x][y][dir(0..4)][cnt(0..3)] // dir=4 means "no previous direction" (start)
    const int DIRS = 5;
    const int MAXCNT = 4; // we store cnt: 0..3 (but valid move cnt will be 1..3)
    vector dist(n, vector(m, vector(DIRS, vector<long long>(MAXCNT, INF))));

    priority_queue<State, vector<State>, greater<State>> pq;
    // start state: at (si,sj), dir = 4 (none), cnt = 0, cost = 0
    dist[si][sj][4][0] = 0;
    pq.push({0, si, sj, 4, 0});

    while (!pq.empty())
    {
        State cur = pq.top();
        pq.pop();
        long long cost = cur.cost;
        int x = cur.x, y = cur.y, dir = cur.dir, cnt = cur.cnt;
        if (cost != dist[x][y][dir][cnt])
            continue;

        // explore 4 neighbors
        for (int nd = 0; nd < 4; ++nd)
        {
            int nx = x + dx[nd], ny = y + dy[nd];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (grid[nx][ny] == '#')
                continue;

            int ncnt;
            if (dir == nd)
            {
                ncnt = cnt + 1;
            }
            else
            {
                ncnt = 1;
            }
            if (ncnt > 3)
                continue; // disallow > 3 consecutive same-dir moves

            long long ncost = cost + 1; // unit weight; change if weighted
            if (dist[nx][ny][nd][ncnt] > ncost)
            {
                dist[nx][ny][nd][ncnt] = ncost;
                pq.push({ncost, nx, ny, nd, ncnt});
            }
        }
    }

    // answer = min over all dir and cnt at (ei,ej)
    long long ans = INF;
    for (int d = 0; d < DIRS; ++d)
    {
        for (int c = 0; c < MAXCNT; ++c)
        {
            ans = min(ans, dist[ei][ej][d][c]);
        }
    }
    if (ans == INF)
        cout << -1 << '\n';
    else
        cout << ans << '\n';

    return 0;
}

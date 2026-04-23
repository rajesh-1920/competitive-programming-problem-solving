// Author:  Rajesh Biswas
// CF    :  rajesh_1920
#include <bits/stdc++.h>
using namespace std;
//----------------------------(definition section)------------------------------------------
#define dbg(x) cout << #x << " = " << x << '\n';
#define int long long int
const double eps = 1e-1;
const int inf = 9e16 + 7;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
const double PI = acos(-1);
const int base1 = 1000002089, base2 = 1000003853, hashmod = 1000002989;
//----------------------------(Order_set)--------------------------------------------------
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
o_set<ll> st;
int pos = st.order_of_key(5);
int val = *st.find_by_order(2);
//---------------------------------------------------------------------------------------*/
//------------------------(Modular-Arithmatic)---------------------------------------------
inline int normal(int a, int m){
    a = a - (a / m) * m;
    if (a < 0)
        a += m;
    return a;
}
inline int modadd(int a, int b, int m){
    a = normal(a, m), b = normal(b, m);
    return normal(a + b, m);
}
inline int modsub(int a, int b, int m){
    a = normal(a, m), b = normal(b, m);
    return normal(a - b, m);
}
inline int modmul(int a, int b, int m){
    a = normal(a, m), b = normal(b, m);
    return normal(a * b, m);
}
inline int binexpo(int a, int b, int m){
    int ans = 1;
    a = normal(a, m);
    while (b){
        if (b & 1)
            ans = modmul(ans, a, m);
        a = modmul(a, a, m);
        b >>= 1;
    }
    return normal(ans, m);
}
inline int moddiv(int a, int b, int m){
    return normal(modmul(a, binexpo(b, m - 2, m), m), m);
}
int outer = 1;
if (is_odd){/////POD
    for (int i = 1; i <= n; i++)
        if (i == posi)
            outer = (outer * ((powe[i] + 1) / 2)) % (MOD - 1);
        else
            outer = (outer * ((powe[i] + 1))) % (MOD - 1);
    for (int i = 1; i <= n; i++)
        pod = modmul(pod, (binexpo(prime[i], _normal(powe[i] * outer, (MOD - 1)), MOD)), MOD);
}
else{
    for (int i = 1; i <= n; i++)
        outer = (outer * ((powe[i] + 1))) % (MOD - 1);
    for (int i = 1; i <= n; i++)
        pod = modmul(pod, (binexpo(prime[i], _normal(powe[i] / 2 * outer, (MOD - 1)), MOD)), MOD);
}
//-----------------------------------------------------------------------------------------*/
// ##########################(String)#########################################################
//--------------------------(Trie Data structure)------------------------------------------
struct node{
    int cnt, nxt[26];
    node(){
        cnt = 0, memset(nxt, -1, sizeof(nxt));
    }
};
vector<node> Trie(1);
inline void add(string &s){
    int root = 0;
    for (int i = 0; i < s.length(); i++){
        if (Trie[root].nxt[s[i] - 'a'] == -1)
            Trie[root].nxt[s[i] - 'a'] = Trie.size(), Trie.emplace_back();
        root = Trie[root].nxt[s[i] - 'a'];
        Trie[root].cnt++;
    }
}
inline int qry(string &s){
    int root = 0;
    for (int i = 0; i < s.length(); i++){
        if (Trie[root].nxt[s[i] - 'a'] == -1)
            return 0;
        root = Trie[root].nxt[s[i] - 'a'];
    }
    return Trie[root].cnt;
}
//-----------------------------------------------------------------------------------------*/
//-------------------------------(KMP)------------------------------------------------------
// LPS array computation
vector<int> computeLPS(string pattern){
    int m = pattern.size();
    vector<int> lps(m, 0);
    int j = 0;
    for(int i = 1; i < m;){
        if(pattern[i] == pattern[j]){
            j++;
            lps[i] = j;
            i++;
        } else {
            if(j != 0) j = lps[j-1];
            else i++;
        }
    }
    return lps;
}
// Count occurrences using KMP
int countOccurrences(string text, string pattern){
    vector<int> lps = computeLPS(pattern);
    int n = text.size(), m = pattern.size();
    int i = 0, j = 0,count = 0;
    while(i < n){
        if(text[i] == pattern[j]){
            i++; j++;
        }
        if(j == m){
            count++; // pattern found
            j = lps[j-1]; // continue searching
        } else if(i < n && text[i] != pattern[j]){
            if(j != 0) j = lps[j-1];
            else i++;
        }
    }
    return count;
}
//----------------------------------------------------------------------------------------*/
//-----------------------------(Manacher’s Algorithm)--------------------------------------
string manacher(const string &s) {
    // Preprocess inside
    string t = "^";
    for (char c : s) t += "#"s + c;
    t += "#$";
    int n = t.size();
    vector<int> p(n, 0);
    int center = 0, right = 0;
    for (int i = 1; i < n - 1; i++) {
        int mirror = 2 * center - i;
        if (i < right)
            p[i] = min(right - i, p[mirror]);
        while (t[i + p[i] + 1] == t[i - p[i] - 1])
            p[i]++;
        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }
    // Find longest palindrome
    int maxLen = 0, centerIndex = 0;
    for (int i = 1; i < n - 1; i++) {
        if (p[i] > maxLen) {
            maxLen = p[i];
            centerIndex = i;
        }
    }
    // Convert to original string index
    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}
//----------------------------------------------------------------------------------------*/
//-----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------*/
// ########################################(DSA)###########################################
//------------(2D Fenwick Tree (point update + rectangle sum))-----------------------------
// fenwick[i][j] = 2D BIT array
// n, m = dimensions (1-indexed)
void fenwick_add(vector<vector<int>>& bit, int n, int m, int x, int y, int val) {
    for (int i = x; i <= n; i += i & -i)
        for (int j = y; j <= m; j += j & -j)
            bit[i][j] += val;
}
int fenwick_sum(const vector<vector<int>>& bit, int x, int y) {
    int s = 0;
    for (int i = x; i > 0; i -= i & -i)
        for (int j = y; j > 0; j -= j & -j)
            s += bit[i][j];
    return s;
}
// rectangle sum query for (x1,y1) to (x2,y2)
int fenwick_range_sum(const vector<vector<int>>& bit,
                     int x1, int y1, int x2, int y2) {
    return fenwick_sum(bit, x2, y2)
         - fenwick_sum(bit, x1 - 1, y2)
         - fenwick_sum(bit, x2, y1 - 1)
         + fenwick_sum(bit, x1 - 1, y1 - 1);
}
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> bit(n + 1, vector<int>(m + 1, 0));
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            // point update: add value at (x, y)
            int x, y, v;
            cin >> x >> y >> v;
            fenwick_add(bit, n, m, x, y, v);
        }
        else {
            // sum of rectangle (x1,y1) to (x2,y2)
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << fenwick_range_sum(bit, x1, y1, x2, y2) << "\n";
        }
    }
}
//----------------------------------------------------------------------------------------*/
//------------------------(Sparse Table (RMQ))----------------------------------------------
// Sparse Table for Range Minimum Query
// 0-indexed array
int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // Precompute logs
    vector<int> lg(n + 1);
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i/2] + 1;
    int K = lg[n]; // max power of two
    // build sparse table
    vector<vector<long long>> st(K+1, vector<long long>(n));
    for (int i = 0; i < n; i++)
        st[0][i] = a[i];
    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[j][i] = min(st[j-1][i], st[j-1][i + (1 << (j-1))]);
    // answer queries
    // each query: L R (0-indexed)
    while (q--) {
        int L, R;
        cin >> L >> R;
        int j = lg[R - L + 1];
        long long ans = min(st[j][L], st[j][R - (1 << j) + 1]);
        cout << ans << "\n";
    }
    return 0;
}
//----------------------------------------------------------------------------------------*/
//---------------------------(SQRT Decompose)-------------------------------------------------
int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    // Compute block size
    int blockSize = sqrt(n) + 1;
    // Precompute block sums
    vector<long long> blockSum(blockSize, 0);
    for(int i = 0; i < n; i++)
        blockSum[i / blockSize] += a[i];
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r; // 0-indexed range [l, r]
        long long sum = 0;
        int startBlock = l / blockSize;
        int endBlock = r / blockSize;
        if(startBlock == endBlock) {
            for(int i = l; i <= r; i++) sum += a[i];
        } else {
            // Partial left block
            int endLeft = (startBlock + 1) * blockSize - 1;
            for(int i = l; i <= min(endLeft, n-1); i++) sum += a[i];
            // Full blocks in between
            for(int b = startBlock + 1; b <= endBlock - 1; b++) sum += blockSum[b];
            // Partial right block
            int startRight = endBlock * blockSize;
            for(int i = startRight; i <= r; i++) sum += a[i];
        }
        cout << sum << "\n";
    }
    return 0;
}
//----------------------------------------------------------------------------------------*/
//---------------------(Mo’s Algorithm)--------------------------------------------------
struct Query {
    int l, r, idx, k; // k is only used for K-th frequency queries
};
int BLOCK;
// Mo's ordering
bool cmp(const Query &a, const Query &b) {
    if (a.l / BLOCK != b.l / BLOCK)
        return a.l / BLOCK < b.l / BLOCK;
    return a.r < b.r;
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int q;
    cin >> q;
    BLOCK = sqrt(n);
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--, queries[i].r--;
        queries[i].idx = i;
        queries[i].k = 0; // default 0 (only for distinct count)
    }
    // Ask user: 1 = distinct count, 2 = K-th frequency
    int mode;
    cout << "Enter mode: 1 = Distinct Count, 2 = K-th Frequent\n";
    cin >> mode;
    if (mode == 2) {
        cout << "Enter K for each query:\n";
        for (int i = 0; i < q; i++)
            cin >> queries[i].k;
    }
    sort(queries.begin(), queries.end(), cmp);
    vector<int> freq(1'000'001, 0);
    vector<int> ans(q);
    int curL = 0, curR = -1;
    int distinct = 0;
    auto add = [&](int pos) {
        if (mode == 1) {
            if (freq[a[pos]] == 0) distinct++;
        }
        freq[a[pos]]++;
    };
    auto remove = [&](int pos) {
        freq[a[pos]]--;
        if (mode == 1) {
            if (freq[a[pos]] == 0) distinct--;
        }
    };
    map<int, set<int>> freqToValues; // for K-th frequent
    for (auto &qq : queries) {
        while (curL > qq.l) add(--curL);
        while (curR < qq.r) add(++curR);
        while (curL < qq.l) remove(curL++);
        while (curR > qq.r) remove(curR--);
        if (mode == 1) {
            ans[qq.idx] = distinct;
        } else {
            // Build frequency → values map
            freqToValues.clear();
            for (int i = qq.l; i <= qq.r; i++)
                freqToValues[freq[a[i]]].insert(a[i]);
            vector<pair<int,int>> best;
            for (auto it = freqToValues.rbegin(); it != freqToValues.rend(); it++) {
                for (int v : it->second)
                    best.push_back({it->first, v});
            }
            if (qq.k > best.size()) ans[qq.idx] = -1;
            else ans[qq.idx] = best[qq.k-1].second;
        }
    }
    cout << "\nAnswers:\n";
    for (int x : ans) cout << x << "\n";
}
//----------------------------------------------------------------------------------------*/
//------------(Longest Incresing Subsequence(LIS)------------------------------------------
vector<int> arr(n);
for (auto &it : arr)
    cin >> it;
vector<int> tail(n + 5, 0);
vector<int> prev(n + 5, -1);
int len = 1;
for (int i = 1; i < n; i++){
    if (arr[i] < arr[tail[0]])
        tail[0] = i;
    else if (arr[i] > arr[tail[len - 1]])
        prev[i] = tail[len - 1],tail[len++] = i;
    else{
        int pos, l = -1, r = len - 1, key = arr[i];
        while (r - l > 1){
            int m = l + (r - l) / 2;
            if (arr[tail[m]] >= key)
                r = m;
            else
                l = m;
        }
        pos = r;
        prev[i] = tail[pos - 1];
        tail[pos] = i;
    }
}
cout << len << '\n';
vector<int> ans;
for (int i = tail[len - 1]; i >= 0; i = prev[i])
    ans.emplace_back(arr[i]);
reverse(all(ans));
for (auto it : ans)
    cout << it << ' ';
//----------------------------------------------------------------------------------------*/
// ################(Number Theory)#####################################################
//-----------------------------(use of sieve)----------------------------------------------
vector<int> lp(N, 0), prime(N, 1), sum(N, 0), pod(N, 1), cnt(N, 0), phi(N);
void sieve()
{
    for (int i = 1; i < N; i++)
        phi[i] = i;
    for (int i = 2; i < N; i++)
    {
        if (phi[i] == i)
            for (int j = i; j < N; j += i)
                phi[j] -= (phi[j] / i);
        // phi(a*b) = phi(a) * phi(b) * (gcd(a, b) / (phi{gcd(a, b)}));
        for (int j = i; j < N; j += i)
        {
            cnt[j]++;
            pod[j] *= i;
            sum[j] += i;
        }
        if (prime[i])
        {
            lp[i] = i;
            for (int j = i + i; j < N; j += i)
            {
                cnt[j]++;
                pod[j] *= i;
                sum[j] += i;
                prime[j] = 0;
                if (!lp[j])
                    lp[j] = i;
            }
        }
    }
}
//----------------------------------------------------------------------------------------*/
//-----------------------------------------------------------------------------------------
// XOR from 0 to n
int xorUpto(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0; // n % 4 == 3
}
// Calculate XOR, AND, OR from l to r
void rangeBitwise(int l, int r) {
    // XOR from l to r
    int resXOR = xorUpto(r) ^ xorUpto(l - 1);
    // AND from l to r
    int resAND = l;
    int a = l, b = r;
    while (a < b) {
        a >>= 1;
        b >>= 1;
        resAND &= ~(1 << __builtin_ctz(resAND+1)); // clear rightmost varying bit
    }
    // OR from l to r
    int resOR = resAND | ((1 << (32 - __builtin_clz(resAND))) - 1) & r;
    cout << "XOR: " << resXOR << "\n";
    cout << "AND: " << resAND << "\n";
    cout << "OR : " << resOR << "\n";
}
//----------------------------------------------------------------------------------------*/
//---------------------------------(number theory)------------------------------------
**snd(p ^ a) = 1 + 2 + 3 + 4 + 5 + -- -- -- -+a + (a + 1);
**n !er prime factor = (n / p) + (n / p ^ 2) + -- -;
**(1 - N) porjonto gcd(i, j) > 1 hobe ? ? ? ?
{
    total possible pair = (N * (N - 1) / 2);
    er por ans = total theke sobgulor coprime number bad jabe..**time komate prefix sum;
    ans = total - pre[N] + (n - 1); // (i==j) er jonno n-1 ta;
}
/minimum number jar divisor sonkha = n
{
    int primearr[]={2,3,5,7,11,13,17,19,23,29,31,37};
    int n;
    int ans(int res_now,int n_now,int ind)
    {
        if(n_now==n)
        return res_now;
        int res=2e8+5;
        for(int i=1;i<=70;i++)
        {
            res_now*=prime[ind];
            if(res_now>res||n_now*(i+1)>n)
            break;
            res=min(res,ans(res_now,n_now*(i+1),ind+1));
        }
        return res;
    }
}
//----------------------------------------------------------------------------------------*/
//------------------------(Dynamic programming)---------------------------------------------
int dp[N];
int ok(int rem_sum, vector<int> &coin) // coin sum
{
    if (rem_sum == 0)
        return 0;
    if (dp[rem_sum] != -1)
        return dp[rem_sum];

    int ans = LONG_LONG_MAX / 2;
    for (auto it : coin)
    {
        if (rem_sum >= it)
            ans = min(ans, (1int + ok(rem_sum - it, coin)));
    }
    rrr dp[rem_sum] = ans;
}
**grid e akti rekhar upor koiti bindu ace jegulo purno sonkha
     ans = gcd((x1 - x2), (y1 - y2)) + 1; // bindu 2 tar katalan distance
//----------------------------------------------------------------------------------------*/

// #############################(Graph theory)###############################################
//-----------------------------(EDGE HLD)------------------------------------------------
long long neutral_value = 0; // SUM:0, MAX:-1e18, MIN:1e18, XOR:0, GCD:0
long long merge_op(long long a, long long b){
    return a + b; // SUM
    // return max(a,b); // MAX
    // return min(a,b); // MIN
    // return a ^ b;    // XOR
    // return gcd(a,b); // GCD
}
long long apply_op(long long nodeVal, long long lazyVal, int len){
    return nodeVal + lazyVal * len; // ADD operation for SUM/MAX/MIN
    // XOR: nodeVal ^ (lazyVal * (len%2))
    // GCD usually needs assignment updates, here we assume ADD
}
long long lazy_op_comb(long long oldLazy, long long newLazy){
    return oldLazy + newLazy; // ADD
    // XOR: oldLazy ^ newLazy
}
vector<int> adj[N];
int parent[N][LOG], depth[N], heavy[N], head[N], pos[N], sz[N];
int cur_pos, base[N], seg[4 * N], lazy[4 * N]; // edge values stored at deeper node
struct Edge{
    int u, v, w;
};
vector<Edge> edges; // input edges
// -------------------- DFS for sizes --------------------
int dfs(int v, int p){
    parent[v][0] = p;
    depth[v] = (p == 0 ? 0 : depth[p] + 1);
    sz[v] = 1, heavy[v] = 0;
    int maxsz = 0;
    for (int c : adj[v]){
        if (c == p)
            continue;
        int sub = dfs(c, v);
        sz[v] += sub;
        if (sub > maxsz)
            maxsz = sub, heavy[v] = c;
    }
    return sz[v];
}
void decompose(int v, int h){
    head[v] = h, pos[v] = ++cur_pos;
    base[cur_pos] = neutral_value; // will assign edge weights later
    if (heavy[v])
        decompose(heavy[v], h);
    for (int c : adj[v]){
        if (c == parent[v][0] || c == heavy[v])
            continue;
        decompose(c, c);
    }
}
// -------------------- Binary Lifting for LCA --------------------
void build_lca(int n){
    for (int v = 1; v <= n; v++)
        for (int k = 1; k < LOG; k++)
            parent[v][k] = parent[parent[v][k - 1]][k - 1];
}
int LCA(int a, int b){
    if (depth[a] < depth[b])
        swap(a, b);
    int d = depth[a] - depth[b];
    for (int k = 0; k < LOG; k++)
        if (d & (1 << k))
            a = parent[a][k];
    if (a == b)
        return a;
    for (int k = LOG - 1; k >= 0; k--)
        if (parent[a][k] != parent[b][k])
            a = parent[a][k], b = parent[b][k];
    return parent[a][0];
}
// -------------------- Segment Tree --------------------
void push(int idx, int l, int r){
    if (lazy[idx] == 0)
        return;
    seg[idx] = apply_op(seg[idx], lazy[idx], r - l + 1);
    if (l != r){
        lazy[idx * 2] = lazy_op_comb(lazy[idx * 2], lazy[idx]);
        lazy[idx * 2 + 1] = lazy_op_comb(lazy[idx * 2 + 1], lazy[idx]);
    }
    lazy[idx] = 0;
}
void build_seg(int idx, int l, int r){
    if (l == r){
        seg[idx] = base[l];
        return;
    }
    int mid = (l + r) / 2;
    build_seg(idx * 2, l, mid);
    build_seg(idx * 2 + 1, mid + 1, r);
    seg[idx] = merge_op(seg[idx * 2], seg[idx * 2 + 1]);
}
void update_range(int idx, int l, int r, int ql, int qr, long long val){
    push(idx, l, r);
    if (qr < l || r < ql)
        return;
    if (ql <= l && r <= qr){
        lazy[idx] = lazy_op_comb(lazy[idx], val);
        push(idx, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update_range(idx * 2, l, mid, ql, qr, val);
    update_range(idx * 2 + 1, mid + 1, r, ql, qr, val);
    seg[idx] = merge_op(seg[idx * 2], seg[idx * 2 + 1]);
}
long long query_range(int idx, int l, int r, int ql, int qr){
    if (qr < l || r < ql)
        return neutral_value;
    push(idx, l, r);
    if (ql <= l && r <= qr)
        return seg[idx];
    int mid = (l + r) / 2;
    return merge_op(query_range(idx * 2, l, mid, ql, qr),
                    query_range(idx * 2 + 1, mid + 1, r, ql, qr));
}
// -------------------- Edge-based HLD PATH --------------------
long long query_path(int u, int v){
    long long res = neutral_value;
    while (head[u] != head[v]){
        if (depth[head[u]] < depth[head[v]])
            swap(u, v);
        res = merge_op(res, query_range(1, 1, cur_pos, pos[head[u]], pos[u]));
        u = parent[head[u]][0];
    }
    if (u == v)
        return res;
    if (depth[u] > depth[v])
        swap(u, v);
    res = merge_op(res, query_range(1, 1, cur_pos, pos[u] + 1, pos[v]));
    return res;
}
void update_path(int u, int v, long long val){
    while (head[u] != head[v]){
        if (depth[head[u]] < depth[head[v]])
            swap(u, v);
        update_range(1, 1, cur_pos, pos[head[u]], pos[u], val);
        u = parent[head[u]][0];
    }
    if (u == v)
        return;
    if (depth[u] > depth[v])
        swap(u, v);
    update_range(1, 1, cur_pos, pos[u] + 1, pos[v], val);
}
void update_edge(int u, int v, long long val){
    int deeper = (depth[u] > depth[v] ? u : v);
    update_range(1, 1, cur_pos, pos[deeper], pos[deeper], val);
}
void assign_initial_edge_values(){
    for (auto &e : edges){
        int deeper = (depth[e.u] > depth[e.v] ? e.u : e.v);
        base[pos[deeper]] = e.w;
    }
}
int main(){
    edges.clear();
    for (int i = 1; i <= n; i++){
        adj[i].clear();
        heavy[i] = 0;
        for (int k = 0; k < LOG; k++)
            parent[i][k] = 0;
        base[i] = neutral_value;
    }
    for (int i = 1; i < n; i++){
        int u, v;
        long long w = 0;
        cin >> u >> v; // read edge
        adj[u].push_back(v), adj[v].push_back(u);
        edges.push_back({u, v, w});
    }
    dfs(1, 0), build_lca(n);
    cur_pos = 0;
    decompose(1, 1), assign_initial_edge_values();
    build_seg(1, 1, cur_pos);

    update_path(u, v, x);                                       // Type 1: add 'x' to all edges along path u→v
    cout << query_path(u, v) << '\n';                           // Type 2: query sum/max/etc of all edges along path u→v
    update_edge(u, v, x);                                       // Type 3: set value of single edge (u,v) to x
    cout << query_range(1, 1, cur_pos, pos[u], pos[u]) << '\n'; // Type 4: query value of edge from parent[u]-u
}
//----------------------------------------------------------------------------------------*/
//-----------------------------(Node HLD)-----------------------------------------------
/*    ✔ SUM :
        neutral_value = 0
        merge_op(a,b) = a+b
        apply_op = nodeValue + lazyValue*len
        lazy_op_comb = oldLazy + newLazy

    ✔ MAX :
        neutral_value = -1e18
        merge_op(a,b) = max(a,b)
        apply_op = nodeValue + lazyValue
        lazy_op_comb = oldLazy + newLazy

    ✔ MIN :
        neutral_value = 1e18
        merge_op(a,b) = min(a,b)
        apply_op = nodeValue + lazyValue
        lazy_op_comb = oldLazy + newLazy

    ✔ XOR :
        neutral_value = 0
        merge_op(a,b) = a ^ b
        apply_op = nodeValue ^ (lazyValue * (len%2))
        lazy_op_comb = oldLazy ^ newLazy

    ✔ GCD :
        neutral_value = 0
        merge_op(a,b) = gcd(a,b)
        apply_op = nodeValue + lazyValue*len     (if update by adding)
        lazy_op_comb = oldLazy + newLazy
/*/
long long neutral_value = 0;
long long merge_op(long long a, long long b){
    return a + b;
}
long long apply_op(long long nodeValue, long long lazyValue, int len){
    return nodeValue + lazyValue * 1LL * len;
}
long long lazy_op_comb(long long oldLazy, long long newLazy){
    return oldLazy + newLazy;
}
vector<int> adj[N];
int parent[N][LOG], depth[N], heavy[N], head[N], pos[N], sz[N];
int value[N], base[N], cur_pos, seg[4 * N], lazy[4 * N];
//-------------------(DFS)---------------------------
int dfs(int v, int p){
    parent[v][0] = p;
    depth[v] = depth[p] + 1, sz[v] = 1;
    int mx = 0;
    for (int c : adj[v]){
        if (c == p)
            continue;
        int sub = dfs(c, v);
        sz[v] += sub;
        if (sub > mx)
            mx = sub, heavy[v] = c;
    }
    return sz[v];
}
void decompose(int v, int h){
    head[v] = h,pos[v] = ++cur_pos;
    base[cur_pos] = value[v];
    if (heavy[v])
        decompose(heavy[v], h);
    for (int c : adj[v])
        if (c != parent[v][0] && c != heavy[v])
            decompose(c, c);
}
//------(LCA -> same as Binary lifting lca (Edge based))---------------------
//------(Segment tree -> same as (Edge based))-------------------------------
//------------(query)----------------
long long query_path(int u, int v){
    long long ans = neutral_value;
    while (head[u] != head[v]){
        if (depth[head[u]] < depth[head[v]])
            swap(u, v);
        ans = merge_op(ans, query_range(1, 1, cur_pos, pos[head[u]], pos[u]));
        u = parent[head[u]][0];
    }
    if (depth[u] > depth[v])
        swap(u, v);
    ans = merge_op(ans, query_range(1, 1, cur_pos, pos[u], pos[v]));
    return ans;
}
void update_path(int u, int v, long long val){
    while (head[u] != head[v]){
        if (depth[head[u]] < depth[head[v]])
            swap(u, v);
        update_range(1, 1, cur_pos, pos[head[u]], pos[u], val);
        u = parent[head[u]][0];
    }
    if (depth[u] > depth[v])
        swap(u, v);
    update_range(1, 1, cur_pos, pos[u], pos[v], val);
}
int main(){
    for (int i = 1; i <= n; i++){
        adj[i].clear();
        heavy[i] = lazy[i] = lazy[i + N] = 0;
    }
    for (int i = 1; i <= n; i++)
        cin >> value[i];
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
    }
    dfs(1, 0);
    build_lca(n);
    cur_pos = 0;
    decompose(1, 1);
    build(1, 1, cur_pos);

    update_path(u, v, x);                                       // Type 1: add +x to every EDGE on path u → v
    cout << query_path(u, v) << '\n';                           // Type 2: query sum/max/min/xor/gcd of all EDGES on path u → v
    update_edge(u, v, x);                                       // Type 3: update the single EDGE (u, v) with value = x
    cout << query_range(1, 1, cur_pos, pos[u], pos[u]) << '\n'; // Type 4: get value of the EDGE between parent[u] → u
}
//----------------------------------------------------------------------------------------*/
//-----------------------------(Topsort)--------------------------------------------------
vector<int> g[N], topo;
int vis[N], cycle;
void dfs(int n){ //BFS using khan's, Indegree 0
    vis[n] = 1;
    for (auto it : g[n]){
        if (vis[it] == 1)
            cycle = 1;
        if (vis[it] == 0)
            dfs(it);
    }
    vis[n] = 2;
    topo.push_back(n);
}
// reverse(all(topo));
// multisource bfs a sob source gulo age queue te jabe
//----------------------------------------------------------------------------------------*/
//------------------------------(DSU)------------------------------------------------------
void _init(vector<int> &tree, vector<int> &cmp){
    for (int i = 0; i < tree.size(); i++)
        tree[i] = i, cmp[i] = 1;
}
int _parrent(int n, vector<int> &tree){
    if (tree[n] == n)
        return n;
    return tree[n] = _parrent(tree[n], tree);
}
bool _make(int u, int v, vector<int> &tree, vector<int> &cmp){
    u = _parrent(u, tree), v = _parrent(v, tree);
    if (u == v)
        return false;
    if (cmp[u] > cmp[v])
        swap(u, v);
    tree[u] = v, cmp[v] += cmp[u];
    return true;
}
//----------------------------------------------------------------------------------------*/
//-------------------------(Dijkstra with extra)-------------------------------------------
// he can move x steps in on direction continiouslyTime Complexity = O(n * m * log(n * m))
struct State{
    long long cost;
    int x, y, dir, cnt;
    // last direction (0=up,1=right,2=down,3=left,4=start) consecutive moves in same direction
    bool operator>(const State &o) const{
        return cost > o.cost;
    }
};
const int X = 3; // max allowed consecutive moves in same direction
// dist[x][y][dir][cnt]
vector dist(n, vector(m, vector(5, vector<long long>(X + 1, INF))));
priority_queue<State, vector<State>, greater<State>> pq;
// Start with special direction=4 (no previous direction), cnt=0
dist[sx][sy][4][0] = 0;
pq.push({0, sx, sy, 4, 0});
while (!pq.empty()){
    State cur = pq.top();
    pq.pop();
    int cost = cur.cost, x = cur.x, y = cur.y, dir = cur.dir, cnt = cur.cnt;
    if (cost != dist[x][y][dir][cnt]) // Skip outdated entries
        continue;
    if (x == tx && y == ty){ // Reached target => minimum cost guaranteed by Dijkstra
        cout << cost << "\n";
        return 0;
    }
    for (int nd = 0; nd < 4; nd++){
        int nx = x + dx[nd], ny = y + dy[nd];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;
        if (g[nx][ny] == '#')
            continue;
        int ncnt = (nd == dir ? cnt + 1 : 1), ncost = cost + 1; // cost per move (changeable)
        if (ncnt > X)
            continue;
        if (dist[nx][ny][nd][ncnt] > ncost){
            dist[nx][ny][nd][ncnt] = ncost;
            pq.push({ncost, nx, ny, nd, ncnt});
        }
    }
}
cout << -1 << "\n"; // Target is unreachable
return 0;
//----------------------------------------------------------------------------------------*/
//------------------------(Belman - Ford Algorithm)----------------------------------------
for (int i = 1; i < V; i++){
    for (auto &e : edges){
        int u = e[0], v = e[1], w = e[2];
        if (dist[u] != INF && dist[u] + w < dist[v])
            dist[v] = dist[u] + w;
    }
}
//----------------------------------------------------------------------------------------*/
//-------------------------(Bridge && ART)---------------------------------------------------
int n, m, timer, tin[N], low[N], vis[N], is_art[N];
vector<pair<int, int>> bridges;
void dfs(int v, int p = -1){
    vis[v] = 1, tin[v] = low[v] = ++timer;
    int child = 0;
    for (int to : g[v]){
        if (to == p)
            continue;
        if (vis[to])
            low[v] = min(low[v], tin[to]);
        else{
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                bridges.push_back({v, to});
            if (low[to] >= tin[v] && p != -1)
                is_art[v] = true;
            child++;
        }
    }
    if (p == -1 && child > 1)
        is_art[v] = true;
}
for (int i = 1; i <= n; i++)
    if (!vis[i])
        dfs(i);
//----------------------------------------------------------------------------------------*/
//------------------------(find bridge online)-----------------------------------------------
// Global variables for the bridge-finding structure
vector<int> par, dsu_2ecc, dsu_cc, dsu_cc_size;
vector<int> last_visit;
int lca_iteration;
int bridges;
// Initialize with n nodes
void init(int n) {
    par.resize(n),dsu_2ecc.resize(n);
    dsu_cc.resize(n),dsu_cc_size.resize(n);
    last_visit.assign(n, 0);
    lca_iteration = 0;
    bridges = 0;
    for (int i = 0; i < n; ++i) {
        par[i] = -1;
        dsu_2ecc[i] = i;
        dsu_cc[i] = i;
        dsu_cc_size[i] = 1;
    }
}
// Find the representative of the 2-edge-connected component
int find_2ecc(int v) {
    if (v == -1) return -1;
    return (dsu_2ecc[v] == v ? v : dsu_2ecc[v] = find_2ecc(dsu_2ecc[v]));
}
// Find the representative of the connected component
int find_cc(int v) {
    v = find_2ecc(v);
    return (dsu_cc[v] == v ? v : dsu_cc[v] = find_cc(dsu_cc[v]));
}
// Re-root the tree at vertex v
void make_root(int v) {
    int root = v, child = -1;
    while (v != -1) {
        int p = find_2ecc(par[v]);
        par[v] = child;
        dsu_cc[v] = root;
        child = v;
        v = p;
    }
    dsu_cc_size[root] = dsu_cc_size[child];
}
void merge_path(int a, int b) {
    ++lca_iteration;
    vector<int> path_a, path_b;
    int lca = -1;
    // Find LCA by marking paths
    while (lca == -1) {
        if (a != -1) {
            a = find_2ecc(a);
            path_a.push_back(a);
            if (last_visit[a] == lca_iteration) {
                lca = a;
                break;
            }
            last_visit[a] = lca_iteration;
            a = par[a];
        }
        if (b != -1) {
            b = find_2ecc(b);
            path_b.push_back(b);
            if (last_visit[b] == lca_iteration) {
                lca = b;
                break;
            }
            last_visit[b] = lca_iteration;
            b = par[b];
        }
    }
    // Compress cycle
    for (int v : path_a) {
        dsu_2ecc[v] = lca;
        if (v == lca) break;
        --bridges;
    }
    for (int v : path_b) {
        dsu_2ecc[v] = lca;
        if (v == lca) break;
        --bridges;
    }
}
// Add edge between a and b, update count of bridges
void add_edge(int a, int b) {
    a = find_2ecc(a),b = find_2ecc(b);
    if (a == b) return;
    int ca = find_cc(a);
    int cb = find_cc(b);
    if (ca != cb) {
        ++bridges;
        // Attach smaller tree under larger tree
        if (dsu_cc_size[ca] > dsu_cc_size[cb]) {
            swap(a, b);
            swap(ca, cb);
        }
        make_root(a);
        par[a] = dsu_cc[a] = b;
        dsu_cc_size[cb] += dsu_cc_size[a];
    } else {
        // They are in same connected component but different 2-edge-connected components
        merge_path(a, b);
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        add_edge(u, v);
        cout << bridges << "\n";
    }
    return 0;
}
//----------------------------------------------------------------------------------------*/
//------------------------(Hamiltonion path for n<=20)--------------------------------------
// HAMILTONIAN PATH: Each node will visit exactly one time
int n, m;
vector<int> g[N];
bool dp[1 << N][N];         // dp[mask][v] = true if we can end at 'v' using nodes in 'mask'
for (int i = 0; i < n; i++) // initialize: single node paths
    dp[1 << i][i] = true;
for (int mask = 0; mask < (1 << n); mask++){ // iterate over all masks
    for (int v = 0; v < n; v++){
        if (!dp[mask][v])
            continue;
        for (int to : g[v]){
            if (mask & (1 << to))
                continue; // already used
            dp[mask | (1 << to)][to] = true;
        }
    }
}
int full = (1 << n) - 1; // check if any full-mask ends somewhere
bool ok = false;
for (int v = 0; v < n; v++)
    if (dp[full][v])
        ok = true;
cout << (ok ? "YES" : "NO") << "\n";
//----------------------------------------------------------------------------------------*/
//-------------------------(K length er path )---------------------------------------------
struct Node {
    long long weight;
    long long count;
};
vector<vector<Node>> multiply(const vector<vector<Node>> &A, const vector<vector<Node>> &B) {
    vector<vector<Node>> C(n, vector<Node>(n, {INF, 0}));
    for(int i = 0; i < n; i++)
        for(int k = 0; k < n; k++)
            if(A[i][k].weight < INF)
                for(int j = 0; j < n; j++)
                    if(B[k][j].weight < INF) {
                        long long new_w = A[i][k].weight + B[k][j].weight;
                        if(new_w < C[i][j].weight) {
                            C[i][j].weight = new_w;
                            C[i][j].count = A[i][k].count * B[k][j].count;
                        } else if(new_w == C[i][j].weight) {
                            C[i][j].count += A[i][k].count * B[k][j].count;
                        }
                    }
    return C;
}
vector<vector<Node>> matrix_power(vector<vector<Node>> base, long long k) {
    vector<vector<Node>> result(n, vector<Node>(n, {INF,0}));
    for(int i = 0; i < n; i++) result[i][i] = {0,1};
    while(k > 0) {
        if(k & 1) result = multiply(result, base);
        base = multiply(base, base);
        k >>= 1;
    }
    return result;
}
int main() {
    long long k;
    cin >> n >> k;
    vector<vector<Node>> G(n, vector<Node>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            long long w;
            cin >> w;
            if(w == -1) G[i][j] = {INF,0};
            else G[i][j] = {w,1};
        }
    auto Lk = matrix_power(G, k);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(Lk[i][j].weight >= INF/2) cout << "-1 0 ";
            else cout << Lk[i][j].weight << " " << Lk[i][j].count << " ";
        }
        cout << "\n";
    }
}
//----------------------------------------------------------------------------------------*/
//-------------------------(Strong orientation )---------------------------------------------
//Undirected ke directed korar por o sob node SCC thakbe O(V+E)
struct Edge { int u, v; };
const int N = 200005;
vector<pair<int,int>> adj[N]; // {neighbor, edge_id}
Edge edges[N];
bool is_bridge[N];
int tin[N], low[N], timer,comp[N];
vector<int> comp_nodes[N];
vector<pair<int,int>> result;
// --- Step 1: Bridge detection ---
void dfs_bridge(int v, int pe = -1){
    tin[v] = low[v] = ++timer;
    for(auto [to,id]: adj[v]){
        if(id == pe) continue;
        if(!tin[to]){
            dfs_bridge(to, id);
            low[v] = min(low[v], low[to]);
            if(low[to] > tin[v]) is_bridge[id] = true;
        } else low[v] = min(low[v], tin[to]);
    }
}
// --- Step 2: 2-edge-connected component labeling ---
void dfs_comp(int v, int c){
    comp[v] = c;
    comp_nodes[c].push_back(v);
    for(auto [to,id]: adj[v]){
        if(comp[to]!=-1 || is_bridge[id]) continue;
        dfs_comp(to,c);
    }
}
// --- Step 3: Strong orientation inside each block ---
void orient_block(int c){
    vector<bool> used(N,false);
    function<void(int)> dfs = [&](int v){
        used[v] = true;
        for(auto [to,id]: adj[v]){
            if(comp[to]!=c) continue;
            if(!used[to]){
                result.push_back({v,to});
                dfs(to);
            } else if(to<v){
                result.push_back({v,to});
            }
        }
    };
    dfs(comp_nodes[c][0]);
}
// --- Step 4: Bridges orientation for minimum SCC ---
void orient_bridges(int m){
    for(int i=0;i<m;i++){
        if(is_bridge[i]){
            int u = edges[i].u, v = edges[i].v;
            if(comp[u]<comp[v]) result.push_back({u,v});
            else result.push_back({v,u});
        }
    }
}
// --- Main function ---
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v; --u; --v;
        edges[i] = {u,v};
        adj[u].push_back({v,i}),adj[v].push_back({u,i});
    }
    for(int i=0;i<n;i++) if(!tin[i]) dfs_bridge(i);
    fill(comp, comp+n, -1);
    int cid = 0;
    for(int i=0;i<n;i++) if(comp[i]==-1) dfs_comp(i,cid++);
    for(int c=0;c<cid;c++) orient_block(c);
    orient_bridges(m);
    for(auto &p: result) cout << p.first+1 << " " << p.second+1 << "\n";
}
//----------------------------------------------------------------------------------------*/
//---------------------(print euler path)-----------------------------------------------------
struct Edge {
    int to;
    bool used = false;
};
const int MAXN = 1000;
vector<Edge> adj[MAXN];
vector<int> path;
bool directed = true;  // set false for undirected
void dfs(int u) {
    for(auto &e : adj[u]) {
        if(!e.used) {
            e.used = true;
            if(!directed) {
                // mark reverse edge as used
                for(auto &rev : adj[e.to]) {
                    if(rev.to == u && !rev.used) {
                        rev.used = true;
                        break;
                    }
                }
            }
            dfs(e.to);
        }
    }
    path.push_back(u);
}
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; // 0-based vertices
        adj[u].push_back({v});
        if(!directed) adj[v].push_back({u});
    }
    // find start vertex
    int start = 0;
    for(int i = 0; i < n; i++) {
        if(!adj[i].empty()) {
            start = i;
            break;
        }
    }
    dfs(start);
    reverse(path.begin(), path.end());
    cout << "Eulerian Path: ";
    for(int v : path) cout << v << " ";
    cout << "\n";
    return 0;
}
//----------------------------------------------------------------------------------------*/
int main()
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
/*
freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
*/
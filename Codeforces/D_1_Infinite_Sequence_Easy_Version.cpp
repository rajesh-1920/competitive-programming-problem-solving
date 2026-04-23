#include <bits/stdc++.h>
using namespace std;

// Function to compute the XOR of the first k terms of the sequence
int computeXOR(const vector<int>& a, int k) {
    int result = 0;
    for (int i = 0; i < k; i++) {
        result ^= a[i];
    }
    return result;
}

// Function to compute a_m for m > n
int computeAM(const vector<int>& a, long long m, int n) {
    if (m <= n) {
        return a[m - 1]; // 0-based indexing
    }
    long long half = m / 2;
    if (half <= n) {
        return computeXOR(a, half);
    } else {
        return computeAM(a, half, n);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Since l = r, we only need to compute a_l
        long long m = l;
        int result;
        if (m <= n) {
            result = a[m - 1]; // 0-based indexing
        } else {
            result = computeAM(a, m, n);
        }

        cout << result << '\n';
    }

    return 0;
}
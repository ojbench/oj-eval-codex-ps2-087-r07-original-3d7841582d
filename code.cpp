#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int d;
    long long n;
    if (!(cin >> d >> n)) return 0;

    const int total_nodes = (1 << d);
    vector<long long> balls(total_nodes, 0);
    balls[1] = n;

    for (int node = 1; node < (1 << (d - 1)); ++node) {
        long long current = balls[node];
        balls[node * 2] = (current + 1) / 2;
        balls[node * 2 + 1] = current / 2;
    }

    int position = 1;
    long long remaining = n;
    for (int level = 1; level < d; ++level) {
        if (remaining & 1LL) {
            position = position * 2;
            remaining = (remaining + 1) / 2;
        } else {
            position = position * 2 + 1;
            remaining /= 2;
        }
    }

    cout << position << '\n';
    for (int leaf = (1 << (d - 1)); leaf < (1 << d); ++leaf) {
        cout << (balls[leaf] & 1LL);
        if (leaf + 1 < (1 << d)) cout << ' ';
    }
    cout << '\n';
    return 0;
}

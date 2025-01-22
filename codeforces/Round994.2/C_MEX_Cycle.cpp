#include <bits/stdc++.h>

// #define ll long long

using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    x--;
    y--;
    vector<int> a(n);
    a[x] = 0, a[y] = 1;

    int tmp = 1;

    if((y - x + 1) % 2) {
        a[x + 1] = 2;
        for(int j = x + 2; j < y; j ++) {
            a[j] = tmp;
            tmp ^= 1;
        }
    } else {
        for(int j = x + 1; j < y; j ++) {
            a[j] = tmp;
            tmp ^= 1;
        }
    }

    tmp = 1;
    if((n - (y - x + 1)) % 2) {
        a[(x - 1 + n) % n] = 2;
        for(int i = x - 2; ((i + n) % n) != y; i --) {
            a[(i + n) % n] = tmp;
            tmp ^= 1;
        }
    } else {
        for(int i = x - 1; ((i + n) % n) != y; i --) {
            a[(i + n) % n] = tmp;
            tmp ^= 1;
        }
    }

    for(int i = 0; i < n; i ++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}
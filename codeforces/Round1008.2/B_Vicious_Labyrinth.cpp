#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    a[n] = n -1;
    a[n - 1] = n;
    for(int i = 1; i <= n - 2; i ++) {
        if(k & 1) {
            a[i] = n;
        } else {
            a[i] = n - 1;
        }
    }
    for(int i = 1; i <= n; i ++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

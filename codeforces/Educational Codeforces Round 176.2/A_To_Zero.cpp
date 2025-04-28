#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n, k, ans = 0;
    cin >> n >> k;
    int j = k - 1;
    if(n & 1) {
        if(k & 1) {
            n -= k;
            ans = 1;
            ans += n / j;
            ans += (n % j) != 0;
        } else {
            n -= j;
            ans = 1;
            ans += n / k;
            ans += (n % k) != 0;
        }
    } else {
        if(k & 1) {
            ans += n / j;
            ans += (n % j) != 0;
        } else {
            ans += n / k;
            ans += (n % k) != 0;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

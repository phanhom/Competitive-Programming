#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    ll x, n, m;
    cin >> x >> n >> m;
    ll x2 = x, n2 = n, m2 = m;
    while(n > 0ll || m > 0ll) {
        if(x == 0ll) break;
        if(x == 1ll) {
            m = 0ll;
        }
        // if(x % 2 == 0) {
            if(m > 0) {
                x = (x + 1ll) / 2ll;
                --m;
            } else if(n > 0) {
                x = x / 2ll;
                --n;
            }
        // } else {
        //     if(n > 0) {
        //         x /= 2ll;
        //         --n;
        //     } else if(m > 0) {
        //         x = (x + 1ll) / 2ll;
        //         --m;
        //     }
        // }
    }
    cout << x << ' ';
    x = x2;
    n = n2;
    m = m2;
    while(n > 0ll || m > 0ll) {
        if(x == 0ll) break;
        if(x == 1ll) {
            m = 0ll;
        }
        // if(x % 2 == 0) {
            if(n > 0) {
                x /= 2ll;
                --n;
            } else if(m > 0) {
                x = (x + 1ll) / 2ll;
                --m;
            }
        // } else {
        //     if(m > 0) {
        //         x = (x + 1ll) / 2ll;
        //         --m;
        //     } else if(n > 0) {
        //         x /= 2ll;
        //        --n;
        //     }
        // }
    }
    cout << x << endl;
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

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

ll n, l, r;
int a[200010], b[200010];

int ss(ll x) {
    if(x <= n) return a[x];
    if(x / 2LL <= n) return b[x / 2LL];
    if(x & 1) {
        return ss(x - 1LL);
    } else {
        return ss(x / 2LL) ^ ss(x - 2LL);
    }
}

void solve() {
    cin >> n >> l >> r;
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i ++) {
        b[i] = b[i - 1] ^ a[i];
        // cout << b[i] << " ";
    }
    // cout << endl;

    cout << ss(l) << endl;

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

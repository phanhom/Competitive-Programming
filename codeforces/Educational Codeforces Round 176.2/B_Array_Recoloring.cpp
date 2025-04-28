#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n, k;
    ll ans = 0;
    cin >> n >> k;
    vector<int> b(n);
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        b[i] = x;
    }
    if(k == 1) {
        if(n == 2) {
            cout << b[0] + b[1] << '\n';
            return;
        }
        sort(b.begin() + 1, b.end() - 1);
        int x1 = b[0], x2 = b[n - 2], x3 = b[n - 1];
        vector<int> tmp;
        tmp.push_back(x1);
        tmp.push_back(x2);
        tmp.push_back(x3);
        sort(tmp.begin(), tmp.end());
        ans += tmp[1] + tmp[2];
        cout << ans << '\n';
        return;
    } else {
        sort(b.rbegin(), b.rend());
    }
    for(int i = 0; i < k + 1; i ++) {
        ans += (ll) b[i];
    }
    cout << ans << '\n';
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

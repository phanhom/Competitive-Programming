#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n, m;
    ll ans = 0;
    cin >> n >> m;
    vector<int> a(n), ra(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> ra[i];
    }
    for(int i = 0; i < n; i ++) {
        int l = a[i] - ra[i];
        int r = a[i] + ra[i];
        for(int j = l; j <= r; j ++) {
            int u = 0;
            int dx = j - a[i];  // 水平距离
            u = sqrt(ra[i] * ra[i] - dx * dx);

            if(mp.count(j)) {
                mp[j] = max(mp[j], u);
            } else {
                mp[j] = u;
            }
        }
    }
    for(auto u : mp) {
        // cout << u.first << " " << u.second << endl;
        ans += u.second * 2 + 1;
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

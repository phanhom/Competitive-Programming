#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    ll n, m;
    ll ans = 0ll;
    cin >> n >> m;
    vector<ll> a(m + 1), suma(m + 1);
    for (ll i = 1; i <= m; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(ll i = 1ll; i <= m; i++) {
        suma[i] = suma[i - 1] + a[i];
    }

    for(ll i = 1; i < m; i++) {
        ll target = n - a[i];
        if(n <= a[i]) {
            ans += (ll) (m - i) * n * 2ll;
            continue;
        }
        
        auto it = lower_bound(a.begin() + i + 1, a.end(), min(target, n));
        if (it != a.end()) {
            ll j = distance(a.begin(), it);
            ll tmp_sum = 0;
            if(a[j] > n && j > i + 1) {
                ll kj = j - 1;
                tmp_sum = suma[kj] - suma[i];
                tmp_sum += (ll) (m - kj) * a[i];
                tmp_sum += (ll) (m - kj);
                ans += (tmp_sum - (ll) n * (m - kj)) * 2ll;
            }
            // tmp_sum = suma[m] - suma[j - 1];
            tmp_sum = (ll) (m - j + 1ll) * a[i] * 2;
            // cout << tmp_sum << endl;
            // tmp_sum += (ll) (m - j + 1ll);
            ans += tmp_sum;
            ans -= (m - j + 1ll) * 2ll;
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

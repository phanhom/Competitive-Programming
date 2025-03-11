#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    ll n, a0 = 0;
    cin >> n;
    vector<ll> a(n * 2ll), g;
    ll sum = 0;
    for (ll i = 0; i < 2ll * n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    g.push_back(a.back());
    for(ll i = 0; i < n - 1ll; ++ i) {
        g.push_back(a[i]);
        g.push_back(a[i + n - 1]);
        sum += abs(a[i] - a[i  + n - 1]);
    }
    sum += g[0];
    sum += a[2 * n - 2];
    g.push_back(sum);
    g.push_back(a[2 * n - 2]);
    for(auto i : g) {
        cout << i << " ";
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

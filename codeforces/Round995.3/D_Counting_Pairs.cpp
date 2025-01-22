#include <bits/stdc++.h>

#define ll long long

// #typedef long long ll;

using namespace std;

void solve() {
    ll n, x, y, sum = 0, ans = 0;
    cin >> n >> x >> y;
    vector<ll> a(n);
    for(int i= 0; i < n; i ++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    ll sum_x = sum - x, sum_y = sum - y;

    for(int i = 0; i < n; i ++) {
        ll lo = sum_y - a[i];
        ll hi = sum_x - a[i];
        auto itlo = lower_bound(a.begin(), a.end(), lo);
        int idx_lo = distance(a.begin(), itlo);
        
        auto ithi = upper_bound(a.begin(), a.end(), hi);
        int idx_hi = distance(a.begin(), ithi);
        idx_hi --;
        idx_lo = max(i + 1, idx_lo);
        if(idx_lo > idx_hi) continue;
        ans += (long long) max(0, idx_hi - idx_lo + 1);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}
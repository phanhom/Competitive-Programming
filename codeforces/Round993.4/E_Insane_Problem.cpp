#include <bits/stdc++.h>

#define ll long long

const ll mx = 1000000001;

void solve() {
    ll k, l1, r1, l2, r2, ans = 0;
    std::cin >> k >> l1 >> r1 >> l2 >> r2;
    std::vector<ll> ks;
    ll tmp = 1;
    for(int i = 1; ; i++) {
        ks.push_back(tmp);
        tmp *= k;
        if(tmp >= mx) break;
    }

    for(ll ki : ks) {
        ll l1k = l1 * ki;
        ll r1k = r1 * ki;
        ll l = std::max(l1k, l2);
        ll r = std::min(r1k, r2);
        if(l > r) continue;
        ans += (r / ki - (l - 1)/ki);
    }

    std::cout << ans << '\n';
}

int main() {
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}
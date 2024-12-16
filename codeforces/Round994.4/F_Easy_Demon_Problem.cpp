#include <bits/stdc++.h>

#define ll long long


void solve() {
    ll n = 0, m = 0, q = 0;
    ll asum = 0, bsum = 0, sum = 0;

    std::cin >> n >> m >> q;
    std::vector<ll> a(n), b(m);
    std::map<ll, std::vector<ll> > ys;
    for(ll i = 0; i < n; i ++) {
        std::cin >> a[i];
        asum += a[i];
    }
    for(ll i = 0; i < m; i ++) {
        std::cin >> b[i];
        bsum += b[i];
    }
    std::set<ll> aa, bb;
    for(ll i = 0; i < n; i ++) {
        a[i] = asum - a[i];
        aa.insert(a[i]);
    }
    for(ll i = 0; i < m; i ++) {
        b[i] = bsum - b[i];
        bb.insert(b[i]);
    }

    for(ll i = 1; i <= 200000; i ++) {
        for(ll j = 1; j * j <= i; j ++) {
            if(i % j == 0) {
                ys[i].push_back(j);
                ys[i].push_back(-1 * j);
            }
        }
    }

    for(ll i = 0; i < q; i ++) {
        ll t;
        std::cin >> t;
        ll abst = std::abs(t);
        bool ans = false;

        std::vector<ll> tmps = ys[abst];

        for(ll j = 0; j < tmps.size(); j ++) {
            ll k = tmps[j];
            if(aa.count(k) && bb.count(t / k)) {
                ans = true;
                break;
            } else if (bb.count(k) && aa.count(t / k)) {
                ans = true;
                break;
            }
        }
        if(ans) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout <<"NO" << std::endl;
        }
    }
}

int main() {
    ll tc = 1;
    // std::cin >> tc;
    while(tc--) { solve(); }
}
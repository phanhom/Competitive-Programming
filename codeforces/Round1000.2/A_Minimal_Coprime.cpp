#include <bits/stdc++.h>
 
using ll = long long;
using pii = std::pair<int, int>;
 
void solve() {
    ll l, r;
    std::cin >> l >> r;

    if(l == r && l == 1) {
        std::cout << 1 << std::endl;
        return;
    }
    ll cnt = 0;
    for(ll a = l; a < r; a ++) {
        if (std::gcd(a, a + 1) == 1) {
            cnt ++;
        }
    }
    std::cout << cnt << std::endl;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}
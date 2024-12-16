#include <bits/stdc++.h>


void solve() {
    int m, a, b, c;
    std::cin >> m >> a >> b >> c;
    int x = std::max(0, m - a);
    int y = std::max(0, m - b);
    int ans = std::min(x + y, c) + std::min(m, a) + std::min(m, b);
    std::cout << ans << std::endl;
}

int main() {
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}
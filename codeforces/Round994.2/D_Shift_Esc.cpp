#include <bits/stdc++.h>
#define ll long long
// using namespace std;

ll dp[510][510], a[510][510];

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < m; j ++) {
            std::cin >> a[i][j];
        }
    }
    memset(dp, 0x3f, sizeof dp);

    dp[0][0] = 0;
    for(int i = 1; i <= n; i ++) {
        for(int shift = 0; shift < m; shift++) {
            std::vector<ll> tmp(m, 1e18);
            for(int j = 0; j < m; j ++) tmp[j] = dp[i - 1][j] + a[i][(j + shift) % m] + k*1LL*shift;
            for(int j = 0; j < m; j ++) tmp[j] = std::min(tmp[j], tmp[(j + m - 1) % m] + a[i][(j + shift) % m]);
            for(int j = 0; j < m; j ++) dp[i][j] = std::min(dp[i][j], tmp[j]);
        }
    }
    std::cout << dp[n][m - 1] << std::endl;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}
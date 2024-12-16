#include <bits/stdc++.h>

// https://codeforces.com/contest/2050

int dp[1010][1010];

void solve()
{
    memset(dp, 0, sizeof dp);
    std::string a, b, c;
    std::cin >> a >> b >> c;
    int n = a.size(), m = b.size();

    for(int i = 1; i <= n; i ++) dp[i][0] = (a[i - 1] != c[i - 1]) + dp[i - 1][0];
    for(int j = 1; j <= m; j ++) dp[0][j] = (b[j - 1] != c[j - 1]) + dp[0][j - 1];
    

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {

            dp[i][j] = std::min(dp[i - 1][j] + (a[i - 1] != c[i + j - 1]), dp[i][j - 1] + (b[j - 1] != c[i + j - 1]));
        }
    }
    std::cout << dp[n][m] << std::endl;
}

int main()
{
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}

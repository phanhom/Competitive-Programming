#include<bits/stdc++.h>

// https://codeforces.com/contest/2040

void solve()
{
    int n, cur = 1;
    std::cin >> n;
    std::vector<std::vector<int> > adj(n);
    std::vector<int> ans(n);
    for(int i = 0; i < n; i ++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }

    auto dfs = [&](int x, int p = -1) -> void {
        ans[x] = cur;
        bool is_first = true;
        for(int s : adj[x]) {
            if(s == p) continue;
            if(is_first) {
                is_first = false;
                cur += 1;
                dfs(s, x);
                cur += 1;
            } else {
                cur += 2;
                dfs(s, x);
            }
        }
    };

    dfs(0);

    for(int i = 0; i < n; i ++) std::cout << ans[i] << ' ';
    std::cout << '\n';
}

int main()
{
    int tc;
    std::cin >> tc;
    while(tc--) { solve(); }
}

#include <bits/stdc++.h>


void solve() {
    int n, ans = 0;
    std::cin >> n;
    std::vector<int> r(n), deg(n), sz(n, 1);

    for(int i = 0; i < n; i ++) {
        std::cin >> r[i];
        r[i] --;
        deg[r[i]] ++;
    }

    std::queue<int> q;
    for(int i = 0; i < n; i ++) if(!deg[i]) q.push(i);

    while(q.size()) {
        int u = q.front();
        q.pop();
        sz[r[u]] += sz[u];
        ans = std::max(ans, sz[u]);
        deg[r[u]] --;
        if(!deg[r[u]]) q.push(r[u]);
    }

    std::cout << ans + 2 << '\n';
}

int main() {
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}
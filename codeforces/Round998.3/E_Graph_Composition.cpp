#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};
void solve() {
    int n, m1, m2;
    std::cin >> n >> m1 >> m2;
    
    DSU g(n);
    std::vector<std::array<int, 2>> ef(m1);
    for (int i = 0; i < m1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        ef[i] = {u, v};
    }
    
    int cg = n;
    for (int i = 0; i < m2; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        cg -= g.merge(u, v);
    }
    
    DSU f(n);
    int cf = n;
    int ans = 0;
    for (auto [u, v] : ef) {
        if (g.same(u, v)) {
            cf -= f.merge(u, v);
        } else {
            ans++;
        }
    }
    
    ans += cf - cg;
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}
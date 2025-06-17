#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

struct DSU {
    vector<int> p;
    DSU(int n): p(n+1, -1) {}
    int find(int x) {
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (p[a] > p[b]) swap(a, b);
        p[a] += p[b];
        p[b] = a;
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    struct Edge { int u, v; ll w; };
    vector<Edge> E(m);
    for (int i = 0; i < m; i++) {
        cin >> E[i].u >> E[i].v >> E[i].w;
    }
    sort(E.begin(), E.end(), [](auto &a, auto &b){
        return a.w < b.w;
    });

    ll ans = LLONG_MAX;
    // 对每个 l，二分找最小 r，使 1 和 n 可连通
    for (int l = 0; l < m; l++) {
        // 如果当前最小边加上自身都已不优，剪枝
        if (2 * E[l].w >= ans) break;

        int lo = l, hi = m - 1, best = m;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            DSU dsu(n);
            for (int i = l; i <= mid; i++) {
                dsu.unite(E[i].u, E[i].v);
            }
            bool can = true;
            for (int i = l; i <= mid; i++) {
                if(dsu.find(i) != dsu.find(E[i].u)) can = false;
            }
            if (dsu.find(1) == dsu.find(n) && can) {
                best = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
                
            }
        }
        if (best < m) {
            ans = min(ans, E[l].w + E[best].w);
        }
    }

    cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}
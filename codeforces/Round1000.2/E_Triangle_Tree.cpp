#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

int n, u, v;
int d[300010], sz[300010], cnt_d[300010];
vector<int> s[300010];
set<int> st;

void dfs(int x, int p) {
    sz[x] = 1;
    for(int i : s[x]) {
        if(i == p) continue;
        d[i] = d[x] + 1;
        dfs(i, x);
        sz[x] += sz[i];
    }
}

void solve() {
    cin >> n;
    vector<int> tmp(n);
    for(int i = 0; i < n; i ++) {
        cin >> u >> v;
        u -= 1, v -=1;
        s[u].push_back(v);
        s[v].push_back(u);
    }

    dfs(0, 0);

    for(int i = 0; i < n; i ++) cnt_d[i] = 0;
    for(int i = 0; i < n; i ++) cnt_d[d[i]] += 1;

    
    
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}
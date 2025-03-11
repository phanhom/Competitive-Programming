#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, st, en;
    cin >> n >> st >> en;

    vector<vector<int> > adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(n + 1, -1);
    queue<int> q;
    q.push(st);
    parent[st] = st;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : adj[node]) {
            if (parent[neighbor] == -1) {
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }

    vector<int> path;
    int cur = en;
    while (cur != st) {
        path.push_back(cur);
        cur = parent[cur];
    }
    path.push_back(st);
    reverse(path.begin(), path.end());

    unordered_set<int> path_set(path.begin(), path.end());

    vector<int> result;
    function<void(int, int)> dfs = [&](int node, int par) {
        for (int neighbor : adj[node]) {
            if (neighbor == par || path_set.count(neighbor)) continue;
            dfs(neighbor, node);
        }
        result.push_back(node);
    };

    for (int node : path) {
        dfs(node, -1);
    }

    
    for (int num : result) cout << num << " ";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
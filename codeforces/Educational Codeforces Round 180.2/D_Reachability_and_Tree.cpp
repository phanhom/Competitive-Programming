#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

map<int, vector<int> > adj;
map<int, set<int> > clan;
set<int> vis;
map<int, int> son_num, parent;


int dfs(int root, bool down) {
    vis.insert(root);
    int tmp_sum = 0;
    for (int son : adj[root]) { 
        if (vis.count(son)) continue;
        parent[son] = root;
        if(down) {
            clan[root].insert(son);
        } else {
            clan[son].insert(root);
        }
        // tmp_sum += dfs(son, !down);
        dfs(son, !down);
        tmp_sum += 1;
    }
    son_num[root] = tmp_sum;
    return tmp_sum + 1;
}

void solve() {
    adj.clear();
    clan.clear();
    vis.clear();
    son_num.clear();
    parent.clear();
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, k;
        cin >> u >> k;
        adj[u].push_back(k);
        adj[k].push_back(u);
    }
    if(n == 2) {
        cout << "NO" << endl;
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(adj[i].size() == 2) {
            cout << "YES\n";
            clan.clear();
            vis.clear();
            son_num.clear();
            parent.clear();
            int left = adj[i][0], right = adj[i][1];
            clan[i].insert(left);
            clan[right].insert(i);
            vis.insert(i);
            dfs(left, false);
            dfs(right, true);
            for(int i = 1; i <= n; i++) {
                for(auto j : clan[i]) {
                    cout << i << " " << j << endl;
                }
            }
            return;
        }
    }
    cout << "NO\n";
    return;
}
 
int main() {
    
    int tc;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}
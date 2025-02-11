#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;
 
void solve() {
    int n, u, v, ans = 0;
    cin >> n;
    vector<vector<int> > a(n);
    vector<int> deg(n);
    multiset<int> ms;

    for(int i = 0; i < n - 1; i ++) {
        cin >> u >> v;
        u --, v --;
        a[u].push_back(v);
        a[v].push_back(u);
        deg[u] ++;
        deg[v] ++;
    }

    for(int i = 0; i < n; i ++) {
        for(int j : a[i]) {
            ans = max(ans, deg[i] + deg[j] - 2);
        }
    }

    for(int i = 0; i < n; i ++) ms.insert(deg[i]);
    for(int i = 0; i < n; i ++) {
        for(auto j : a[i]) ms.erase(ms.find(deg[j]));
        ms.erase(ms.find(deg[i]));
        if(!ms.empty()) ans = max(ans, (int) deg[i] + *ms.rbegin() - 1);
        ms.insert(deg[i]);
        for(auto j : a[i]) ms.insert(deg[j]);
    }
    cout << ans << endl;

}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}
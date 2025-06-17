#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> rooms(m);
    for (int i = 0; i < m; ++i) {
        cin >> rooms[i];
    }
    sort(rooms.begin(), rooms.end());
    int idx = 0;
    vector<pii> ans(n);
    for(int i = 0; i < n; ++i) {
        ans[i] = make_pair(rooms[idx], rooms[m - idx - 1]);
        if(i + 1 < n) {
            ans[i + 1] = make_pair(rooms[m - idx - 1], rooms[idx]);
            i ++;
        }
        idx ++;
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 3; j ++) {
            cout << ans[i].first << " " << ans[i].second << " ";
        }
        cout << endl;
    }
}

 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}
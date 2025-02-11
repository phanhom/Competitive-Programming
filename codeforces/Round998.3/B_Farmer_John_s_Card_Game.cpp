#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    vector<vector<int> > card(n, vector<int>(m));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> card[i][j];
        }
        sort(card[i].begin(), card[i].end());
        mp[card[i][0]] = i + 1;
    }
    sort(card.begin(), card.end());
    int pre = -1;
    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j ++) {
            // cout << card[j][i] << ' ';
            if(card[j][i] <= pre) {
                cout << -1 << endl;
                return;
            }
            pre = card[j][i];
        }
        // cout << endl;
    }
    for(int i = 0; i < n; i ++) {
        cout << mp[card[i][0]] << ' ';
    }
    cout << endl;

}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}
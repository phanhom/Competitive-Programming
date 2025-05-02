#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n, ans = 0, tmp = 1;
    cin >> n;
    vector<int> a(n);
    vector<pii> idx;
    set<int> canbe;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if(i && a[i] == a[i - 1]) continue;
        idx.push_back(make_pair(a[i], tmp));
        tmp ++;
    }
    sort(idx.rbegin(), idx.rend());
    for(int i = 0; i < idx.size(); i ++) {
        if(!canbe.count(idx[i].second)) {
            ans ++;
        }
        canbe.insert(idx[i].second);
        canbe.insert(idx[i].second - 1);
        canbe.insert(idx[i].second + 1);
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
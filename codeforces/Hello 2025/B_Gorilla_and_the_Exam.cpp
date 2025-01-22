#include <bits/stdc++.h>
using ll = long long;
// using namespace std;

void solve() {
    std::map<int, int> mp;
    int n, m, idx = 0;
    std::cin >> n >> m;
    std::vector<int> a(n), b;
    for(int i = 0; i < n; i ++) {
        std::cin >> a[i];
        mp[a[i]] ++;
    }
    if (n == m) {
        std::cout << 1 << std::endl;
        return;
    }
    
    for(auto &x : mp) b.push_back(x.second);
    sort(b.begin(), b.end());
    int ans = b.size();

    while(m > 0 && idx < ans) {
        m -= b[idx];
        if(m < 0) break;
        idx ++;
    }
    ans -= idx;
    std::cout << ans << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}
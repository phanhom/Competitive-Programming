#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;


void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i ++) {
        for(auto &x : b) cin >> x;
        while(a[i] < n && b[n - 1 - a[i]] == 1) a[i] ++;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        if(a[i] >= ans) ans ++;
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
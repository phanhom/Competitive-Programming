#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    if(m - n == 1) {
        cout << "YES\n";
    } else {
        if(n >= m && (m - n - 1) % 9 == 0) cout << "YES\n";
        else cout << "NO\n";
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
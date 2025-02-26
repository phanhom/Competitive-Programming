#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n, k, p, sum = 0;
    cin >> n >> k >> p;
    k = abs(k);
    if(k > n * p) {
        cout << "-1\n";
        return;
    }
    int ans = k / p;
    int r = k % p;
    cout << ans + (r != 0) << endl;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}
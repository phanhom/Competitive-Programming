#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int k, a, b, x, y, res = 0;
    cin >> k >> a >> b >> x >> y;

    if(y < x) {
        swap(x, y);
        swap(a, b);
    }

    if(k >= a) {
        res += (k - a) / x + 1;
        k -= res * x;
    }

    if(k >= b) {
        res += (k - b) / y + 1;
    }
    
    res = max(0, res);
    cout << res << endl;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}
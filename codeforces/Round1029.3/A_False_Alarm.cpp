#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n, x;
    cin >> n >> x;
    int first = n, end = -1, tmp;
    for(int i = 0; i < n; i ++) {
        cin >> tmp;
        if(tmp == 1) {
            first = min(first, i);
            end = max(end, i);
        }
    }
    if(x >= max(0, end - first + 1)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
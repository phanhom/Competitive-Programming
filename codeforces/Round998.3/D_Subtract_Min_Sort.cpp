#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < n - 1; i ++) {
        if(a[i] > a[i + 1]) {
            cout << "NO\n";
            return;
        }
        a[i + 1] -= a[i];
        a[i] = 0;
    }
    cout << "YES\n";
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}
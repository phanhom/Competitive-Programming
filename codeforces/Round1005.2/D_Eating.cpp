#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    reverse(a.begin(), a.end());
    for(int i = 1; i < n; i ++) a[i] ^= a[i - 1];
    while(q --) {
        int x;
        cin >> x;
        cout << '-' << x << endl;
    }
    for(int i = 0; i < n; i ++) cout << a[i] << ' ';
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
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i ++) {
        int l = i, r = n - i - 1;
        if(a[i] <= 2 * l || a[i] <= 2 * r) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}
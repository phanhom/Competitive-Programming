#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n, m, x;
    cin >> n >> m;
    vector<int> a(n);
    for(int &k : a) cin >> k;
    cin >> x;
    a[n - 1] = max(a[n - 1], x - a[n - 1]);
    for(int i = n - 2; i >= 0; -- i) {
        int a1 = a[i], a2 = x - a[i];
        if(min(a1, a2) > a[i + 1]) {
            cout << "NO\n";
            return;
        }
        if(max(a1, a2) <= a[i + 1]) a[i] = max(a1, a2);
        else if(a1 > a[i + 1]) a[i] = a2;
        else a[i] = a1;
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
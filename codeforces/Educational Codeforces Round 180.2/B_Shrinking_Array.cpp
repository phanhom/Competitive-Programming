#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n;
    cin >> n;
    int ans = n + 2;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        int j = i, mn = a[i], mx = a[i];
        for(; j < n; j ++) {
            if(j < n - 1) {
                int target = j + 1;
                mn = min(mn, a[j]);
                mx = max(mx, a[j]);
                if(a[target] <= mx + 1 && a[target] >= mn - 1) {
                    ans = min(ans, j - i);
                }
            }
            if(i > 0) {
                int target = i - 1;
                mn = min(mn, a[j]);
                mx = max(mx, a[j]);
                if(a[target] <= mx + 1 && a[target] >= mn - 1) {
                    ans = min(ans, j - i);
                }
             }
        }
    }
    if(ans == n + 2) {
        ans = -1;
    }
    cout << ans << "\n";
    
}
 
int main() {
    
    int tc;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}
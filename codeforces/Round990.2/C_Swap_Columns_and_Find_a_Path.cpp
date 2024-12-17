#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
    int n, ans = 0, mx = -1000000;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < n; i ++) cin >> b[i];
    
    for(int i = 0; i < n; i ++) {
        if(a[i] > b[i]) {
            ans += a[i];
            mx = max(mx, b[i]);
        } else {
            ans += b[i];
            mx = max(mx, a[i]);
        }
    }
    cout << ans + mx << endl;
}

int main() {
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}
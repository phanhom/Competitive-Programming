#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<array<ll, 2> > f(n);
    // f[i][0] = 当前还没选负数到i的最大值
    // f[i][1] = 当前选负数到i的最大值
    for(int i = 0; i < n; i++) cin >> a[i];
    if(a[0] < 0) f[0][1] = abs(a[0]);
    else f[0][0] = abs(a[0]);
    for(int i = 1; i < n; i ++) {
        if(a[i] >= 0) {
            f[i][0] = f[i - 1][0] + abs(a[i]);
            f[i][1] = f[i - 1][1];
        } else {
            f[i][1] = max(f[i - 1][0], f[i - 1][1]) + abs(a[i]);
            f[i][0] = f[i - 1][0];
        }
    }
    // for(int i = 0; i < n; i ++) cout << f[i][0] << ' ';
    // cout << endl;
    // for(int i = 0; i < n; i ++) cout << f[i][1] << ' ';
    cout << max(f[n - 1][0], f[n - 1][1]) << '\n';
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for(int i = 0; i < n; ++ i) cin >> a[i];
    for(int i = 0; i < m; ++ i) cin >> b[i];
    sort(b.begin(), b.end());
    a.push_back(a[n - 1] + b[m - 1] * 2LL);

    for(int i = n - 1; i >= 0; -- i) {
        ll lim = a[i] + a[i + 1];
        auto it = upper_bound(b.begin(), b.end(), lim);
        if(it == b.begin()) {
            if(a[i] > a[i + 1]) {
                cout << "NO\n";
                return;
            }
            continue;
        }
        int idx = (it - b.begin() - 1);
        int a1 = a[i], a2 = b[idx] - a[i];
        // cout << a1 << '-' << a2 << '?';
        if(min(a1, a2) > a[i + 1]) {
            cout << "NO\n";
            return;
        }
        if(max(a1, a2) <= a[i + 1]) a[i] = max(a1, a2);
        else if(a1 > a[i + 1]) a[i] = a2;
        else a[i] = a1;
    }
    // for(auto i : a) cout << i << '-';
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
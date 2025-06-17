#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i ++) cin >> a[i];
    for(ll i = 2; i < n; i ++) {
        if(a[i] - a[i - 1] != a[i - 1] - a[i - 2]) {
            cout << "NO\n";
            return;
        }
    }
    ll b_a = a[0] - a[1];
    ll b_times_n_plus_1 = a[0] + b_a;
    // cout << b_a << '-' << b_times_n_plus_1 << endl;
    if(b_times_n_plus_1 % (n + 1) == 0) {
        ll b = b_times_n_plus_1 / (n + 1);
        ll aa = b - b_a;
        if(aa < 0 || b < 0) {
            cout << "NO\n";
            return;
        }
        for(ll i = 0; i < n; i ++) {
            if(a[i] != (ll) aa * (i + 1) + b * (n - i)) {
                cout << "NO\n";
                return;
            }
        }
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